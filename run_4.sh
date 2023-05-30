sudo chrt -f 90 sudo taskset -c 5 sudo ./txrx-tsn -P -h -ri enp11s0 -q 2 -n 500000 > log.txt
