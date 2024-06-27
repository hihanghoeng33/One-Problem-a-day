int findCenter(int** edges, int edgesSize, int* edgesColSize) {
    int node1 = edges[0][0];
    int node2 = edges[0][1];
    int node3 = edges[1][0];
    int node4 = edges[1][1];

    if (node1 == node3 || node1 == node4) {
        return node1;
    } else {
        return node2;
    }
}