#pragma once

#include <stdint.h>
#include <stdio.h>
#define MAX_RECORD 10000000

struct record {
    // u2u latency, seq, queue, user txtime, hw rxtime,sw rxtime, user rxtime
    uint64_t e2e_lat;
    uint32_t seq;
    uint32_t queue;
    uint64_t user_tx;
    uint64_t hw_rx;
    uint64_t sw_rx;
    uint64_t user_rx;
};

struct dump_tstamp {
    struct record recs[MAX_RECORD];
    int record_idx;
};

static void record(struct dump_tstamp * dts, uint64_t a, uint32_t b, uint32_t c, uint64_t d, uint64_t e, uint64_t f, uint64_t g)
{
    dts->recs[dts->record_idx].e2e_lat = a;
    dts->recs[dts->record_idx].seq = b;
    dts->recs[dts->record_idx].queue = c;
    dts->recs[dts->record_idx].user_tx = d;
    dts->recs[dts->record_idx].hw_rx = e;
    dts->recs[dts->record_idx].sw_rx = f;
    dts->recs[dts->record_idx].user_rx = g;
    dts->record_idx++;
    if(dts->record_idx >= MAX_RECORD) //drop
        return ;
}

static void dump(struct dump_tstamp * dts)
{
    for(int i=0;i<(dts->record_idx > MAX_RECORD ? MAX_RECORD: dts->record_idx);i++)
    {
        fprintf(stdout, "%ld\t%d\t%d\t%ld\t%ld\t%ld\t%ld\n",
                dts->recs[i].e2e_lat,
                dts->recs[i].seq,
                dts->recs[i].queue,
                dts->recs[i].user_tx,
                dts->recs[i].hw_rx,
                dts->recs[i].sw_rx,
                dts->recs[i].user_rx);
    }
}