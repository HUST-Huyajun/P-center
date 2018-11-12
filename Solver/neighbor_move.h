#ifndef PCH_H
#define PCH_H
#include "Common.h"
#include "Utility.h"

#include<vector>
#include<unordered_map>
using namespace std;
class serveS {
public:
	vector<int>S;
	vector<int>index;
	vector<bool>whether;
	int len;
	serveS(int n, int p);
	void addF(int F);
	void deleteF(int F);
	void show();
	int randget();
	void clear();
	bool exist(int F);
	vector<int> get_serves();
};
class node {
public:
	int n;
	vector<int> D_first;
	vector<int> D_second;
	vector<int> F_first;
	vector<int> F_second;
	node(int n);
	void show();
};
class Algorithm_paraments {
private:
	int  tabu_step;
	int total_iterations;
	int reward_value;
	int period_threshold;
public:
	void set_tabu_step(int a);
	void set_total_iterations(int a);
	void set_reward_value(int a);
	void set_period_threshold(int a);
	int get_tabu_step();
	int get_total_iterations();
	int get_reward_value();
	int get_period_threshold();
};
class P_center_action {
public:
	string instname;
	void set_opt();
	unordered_map<string, int>bestopt;
	unordered_map<string, int>mybetteropt;


	serveS m;
	node point;

	
	vector<int> M;//M[f]代表删除f的话新增的最长边；
	vector<vector<int>>G;
	int n;
	int p;
	P_center_action(string instance_name,int n, int p, Algorithm_paraments paraments, szx::Arr2D<szx::Length>Graph);
	int caculate_opt();
	void show_M();
	int select_maxlen_edge(int &user, int &serve);
	int select_Nk(int i);
	vector<int> give_Nwk(int w);
	void add_facility(int newserve);
	int find_next(int user);
	void remove_facility(int oldserve);
	void caculate_M(int newserve);
	void BEGIN();
	int find_pair(int& add, int& remove, int t, int best_opt);
	int neighbour_action(int &add, int &remove, int t, int best_opt);
public://search
	vector<vector<int>>tabu_list;
	Algorithm_paraments paraments;
	int get_tt();
	int search(vector<int>& opt_serves);
public:
	void reset();
};
#pragma once

#endif //PCH_H
