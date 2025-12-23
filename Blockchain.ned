simple UserNode {
    parameters:
        @display("i=device/laptop;is=s");
    gates:
        inout port[];
}

simple MinerNode {
    parameters:
        @display("i=device/server;is=l;r=200");
    gates:
        inout port[];
}

network BlockchainNet {
    parameters:
        int numUsers = default(10);
        int numMiners = default(3);
        @display("bgb=800,600;bgi=maps/world,s");
    submodules:
        miners[numMiners]: MinerNode {
            @display("p=400,300,ring,100");
        }
        users[numUsers]: UserNode {
            @display("p=400,300,ring,250");
        }
    connections allowunconnected:
        for i=0..numUsers-1, for j=0..numMiners-1 {
            users[i].port++ <--> { delay = 100ms; } <--> miners[j].port++;
        }
        for i=0..numMiners-1, for j=0..numMiners-1 {
            miners[i].port++ <--> { delay = 50ms; } <--> miners[j].port++ if i!=j;
        }
}