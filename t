To implement a program that demonstrates load balancing 
by distributing processes evenly among available servers in a distributed system.


Theory 
Load balancing is a technique used in distributed systems to distribute workload 
evenly across multiple servers. This improves system performance, efficiency, and resource utilization.

In this approach:

The total number of processes is divided among servers.
Each server gets an equal number of processes.
If processes are not equally divisible, extra processes are distributed one by one to the first few servers.
Formula used:

Each server load = processes / servers
Extra load = processes % servers
This ensures fair and efficient distribution of tasks.

Conclusion 
The program successfully demonstrates load balancing by distributing processes 
equally among servers. It ensures efficient utilization of resources and 
improves system performance in a distributed environment
