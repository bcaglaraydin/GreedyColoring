#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include<numeric>

using namespace std;

//function to return ajdacent vertices to the given vertex
vector <int> get_adj(int v, vector<vector<bool>> adj) {
	vector<int> v_adj;
	for (int j = 0; j < adj[v].size(); j++)
	{
		if (adj[v][j]) {
			v_adj.push_back(j);
		}
	}
	return v_adj;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	//initializing the graph
	vector<vector<bool>> adj{ {0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{1,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,1,1,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,1,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0}
	};
	//number of vertices
	int V = adj[0].size();

	//finding the degrees of all vertices
	vector<int> deg(V);
	for (int i = 0; i < V; i++) {
		deg[i] = count(adj[i].begin(), adj[i].end(), 1);
	}

	//sort vertices in descending order of degrees
	vector<int> vertices(deg.size());
	iota(vertices.begin(), vertices.end(), 0);
	stable_sort(vertices.begin(), vertices.end(), [&deg](size_t i1, size_t i2) {return deg[i1] > deg[i2]; });

	//initialize colors
	vector<int> v_colors(V);
	fill(v_colors.begin(), v_colors.end(), 0);


	vector<int> erased; //keep track of erased vertices
	int c = 1; //first color
	int curr_vertex;
	while (!vertices.empty()) { //loop until degree_list is empty
		curr_vertex = vertices.front(); //get the current vertex (vertex with highest degree)
		v_colors[curr_vertex] = c; //color the vertex with the new color
		cout << "Vertex " << curr_vertex + 1 << " --> Color " << c << endl;

		vertices.erase(remove(vertices.begin(), vertices.end(), curr_vertex), vertices.end()); //remove it from the degree_list

		auto adj_v = get_adj(curr_vertex, adj); //get adjacent vertices

		for (auto i = vertices.begin(); i != vertices.end(); ++i) {
			cout << "Checking " << *i + 1 << " ---> ";

			if (!any_of(adj_v.begin(), adj_v.end(), [&](const int& elem) { return elem == *i; }) && *i != curr_vertex) {
				//for each vertex which is not adjacent
				auto a = get_adj(*i, adj); //get adjacent vertexes
				bool b = true;
				int connected;

				for (auto j = a.begin(); j != a.end(); ++j) { //check if any adjacent have the same color
					if (v_colors[*j] == c) { //if there is, save the vertex and set b=false
						connected = *j;
						b = false;
					}
				}

				if (b) { //if everything is OK, color the vertex, save it for the remove operation
					v_colors[*i] = c;
					erased.push_back(*i);
					cout << "true" << endl;
					cout << "Vertex " << *i + 1 << " --> Color " << c << endl;
				}
				else {
					cout << "false (since it is connected to " << connected + 1 << ")" << endl;
				}
			}
			else {
				cout << "false" << endl;
			}
		}

		//remove colored vertices from the degree_list
		cout << "Vertices ";
		cout << curr_vertex + 1 << " ";
		for (int i = 0; i < erased.size(); i++) {
			cout << erased[i] + 1 << " ";
			vertices.erase(remove(vertices.begin(), vertices.end(), erased[i]), vertices.end());
		}
		cout << "are dropped!!" << endl;

		erased.clear(); //reset erased for the next iteration

		c++; //switch color
		cout << endl;
	}

	cout << "Well done!! All the vertices are colored." << endl;
	cout << "Min color num:" << c - 1 << endl;

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
	cout << "The running time: " << duration.count() << "ms" << endl;

	return 0;
}



