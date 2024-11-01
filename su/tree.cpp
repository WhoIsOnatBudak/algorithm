#include <bits/stdc++.h>
using namespace std;

vector<long long> coinValues;    
vector<vector<long long>> adjacencyList; 
vector<bool> isVisited;       
vector<long long> computedValues;   

long long computeValue(long long currentNode) {
    isVisited[currentNode] = true;

    vector<long long> childValues;

    for (long long childNode : adjacencyList[currentNode]) {
        if (!isVisited[childNode]) {
            childValues.push_back(computeValue(childNode));
        }
    }

    if (childValues.empty()) {
        computedValues[currentNode] = coinValues[currentNode];
        return computedValues[currentNode];
    }

    if (childValues.size() == 1) {
        computedValues[currentNode] = coinValues[currentNode];
    } else {
        sort(childValues.rbegin(), childValues.rend());
        computedValues[currentNode] = childValues[1] + coinValues[currentNode];
    }

    return computedValues[currentNode];
}

int main() {
    long long numberOfNodes; 
    cin >> numberOfNodes;

    adjacencyList.resize(numberOfNodes);
    coinValues.resize(numberOfNodes);
    isVisited.resize(numberOfNodes, false);
    computedValues.resize(numberOfNodes);

    for (long long i = 0; i < numberOfNodes - 1; i++) {
        long long firstNode, secondNode;
        cin >> firstNode >> secondNode;
        firstNode--;
        secondNode--;
        adjacencyList[firstNode].push_back(secondNode);
        adjacencyList[secondNode].push_back(firstNode);
    }

    for (long long i = 0; i < numberOfNodes; i++) {
        cin >> coinValues[i];
    }

    computeValue(0);

    cout << "Total Gold: " << computedValues[0] << endl;

    return 0;
}
