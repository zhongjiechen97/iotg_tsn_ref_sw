sudo chrt -f 90 sudo taskset -c 5 sudo ./txrx-tsn -PT -ti enp10s0 -q 3 -n 500000 -l 64 -y 250000 -e 250000 -o 2000000
