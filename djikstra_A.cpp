#include <iostream>
#include <map>
#include <string>
#include <set>



using namespace std;


map<string, map<string, int>> graph;
map<string, int> cost;
map<string, string> parents;
set<string> blacklist;


void cetak_jarak(){


//this is your code and x
//and its also require you to

}
string pilih_node_bobot_terendah(map<string, int> cost){

int bobot_terendah = 900000000;
string node_bobot_terendah = "None";

for(auto& [key, value]: cost){
    int bobot = value;
    //cek apakah bobot lebih rendah, dan apakah node sudah pernah diproses
    if (bobot < bobot_terendah && blacklist.find(key) == blacklist.end()){
        bobot_terendah = bobot;
        node_bobot_terendah = key;
    }
}

return node_bobot_terendah;
}


int main(){

cost["B"] = 2;
cost["A"] = 6;
cost["F"] = 900000000;

parents["B"] = "Start";
parents["A"] = "Start";
parents["F"] = "None";

graph["Start"]["A"] = 6;
graph["Start"]["B"] = 2;
graph["B"]["A"] = 3;
graph["B"]["F"] = 7;
graph["A"]["F"] = 1;

//pilih node dgn bobot terkecil
string node = pilih_node_bobot_terendah(cost);

//cek apakah node kosong atau tidak, kalau tidak kosong proses
while(node != "None"){

    //ambil bobot dari node
    int bobot = cost[node];

    //cek seluruh node anggota dari node yg terpilih
    for(auto& [key, value]: graph[node]){
        int bobot_update = bobot + value;
        if(cost[key] > bobot_update){
            cost[key] = bobot_update;
            parents[key] = node;
        }
    }
    //masukan node yg terpilih saat ini ke dalam blacklist
    blacklist.insert(node);
    node = pilih_node_bobot_terendah(cost);
}


for(auto& [key, value]: parents){
    cout<<"Node: "<<key<<", Induknya adalah: "<<value<<endl;
}

}
