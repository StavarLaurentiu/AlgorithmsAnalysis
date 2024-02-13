
TSP(V, E) {
    // Generate
    road = [];
    for (i = 1:V.size) {
        X = choice(V);

        if (road.contains(X)) 
            fail();
        else 
            road.append(X);
    }

    // Verify
    for (i = 0:V.size - 2) {
        if (!E.contains(road[i], road[i+1]))
            fail();
    }

    if (!E.contains(road[V.size - 1], road[0]))
        fail();

    success();
}