#include"neighbor_move.h"
#include "Utility.h"
#include "Common.h"

#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>


#include <fstream>
#include <sstream>
using namespace std;
serveS::serveS(int n, int p) :whether(n + 1, 0), index(n + 1, 0), S(p + 2, 0) {
	len = 0;
}
void serveS::addF(int F) {
	len++;
	S[len] = F;
	index[F] = len;
	whether[F] = true;
	return;
}
void serveS::deleteF(int F) {
	if (whether[F] == false) {
		printf("%d is not in S,don't delete it.\n", F);
		return;
	}
	whether[F] = false;
	S[index[F]] = S[len];
	index[S[len]] = index[F];
	len--;
	index[F] = 0;
	return;
}
void serveS::show() {
	printf("the serves are:");
	for (int i = 1; i <= len; i++)
		std::cout << S[i] << " ";
	std::cout << std::endl;
	return;
}
int serveS::randget() {
	return S[rand() % len + 1];
}
void serveS::clear() {
	len = 0;
}
bool serveS::exist(int F) {
	return whether[F];
}
vector<int> serveS::get_serves() {
	vector<int> ret;
	for (int i = 1; i <= len; i++)
		ret.push_back(S[i]);
	return ret;
}
node::node(int n) :D_first(n + 1), D_second(n + 1), F_first(n + 1), F_second(n + 1) { node::n = n; }
void node::show() {
	for (int i = 1; i <= n; i++)
		printf("node %d:first:%d->%d second:%d->%d\n", i, F_first[i], D_first[i], F_second[i], D_second[i]);
	return;
}
void Algorithm_paraments::set_tabu_step(int a) { tabu_step = a; }
void Algorithm_paraments::set_period_threshold(int a) { period_threshold = a; }
void Algorithm_paraments::set_tabu_type(string a) { 
	if (a == "couple" || a == "double")
		tabu_type = a;
	else
		printf("no this tabu type!\n");
}
void Algorithm_paraments::set_k(int a) { k_of_Nwk = a; }
void Algorithm_paraments::set_seed(int a){seed = a;}
void Algorithm_paraments::set_time_limits(int a){time_limits = a;}
void Algorithm_paraments::set_reward_value(int a) { reward_value = a; }
void Algorithm_paraments::set_total_iterations(int a) { total_iterations = a; }
int Algorithm_paraments::get_tabu_step() { return tabu_step; }
int Algorithm_paraments::get_total_iterations() { return total_iterations; }
int Algorithm_paraments::get_reward_value() { return reward_value; }
int Algorithm_paraments::get_period_threshold() { return period_threshold; }
string Algorithm_paraments::get_tabu_type(){return tabu_type;}
int Algorithm_paraments::get_k(){return k_of_Nwk;}
int Algorithm_paraments::get_seed(){return seed;}
int Algorithm_paraments::get_time_limits(){return time_limits;}
tabu::tabu(int n, Algorithm_paraments a) {
	paraments = a;
	if (a.get_tabu_type() == "couple") {
		tabu_list_couple.resize(n + 1, vector<int>(n + 1, 0));
		tabu_list_serve.resize(0, 0);
		tabu_list_user.resize(0, 0);
	}
	else if (a.get_tabu_type() == "double") {
		tabu_list_couple.resize(0, vector<int>(0, 0));
		tabu_list_serve.resize(n + 1, 0);
		tabu_list_user.resize(n + 1, 0);
	}
	else {
		printf("no this tabu type!\n");
	}
	return;
}
int tabu::get_tt() {
	return paraments.get_tabu_step() + rand() % (paraments.get_tabu_step() / 3) ;//引入疏散性
}
bool tabu::whether_tabu(int add, int remove, int t) {
	if (paraments.get_tabu_type() == "couple") {
		return tabu_list_couple[remove][add] <= t;//加入禁忌 tabu_list[remove][add]
	}
	else if (paraments.get_tabu_type() == "double") {
		return (tabu_list_serve[add] <= t) && (tabu_list_user[remove] <= t);
		//return (tabu_list_serve[add] <= t) || (tabu_list_user[remove] <= t);
	}
	else {
		printf("no this tabu type!\n");
		return false;
	}
}
void tabu::modify_tabu(int add, int remove, int t)
{
	int tabu_step = get_tt() + t;
	tabu_list_couple[remove][add] = tabu_step;
	tabu_list_couple[add][remove] = tabu_step;
}
int tabu::get_mintabu(int add, int remove,int mintabu)
{
	if (paraments.get_tabu_type() == "couple") {
		mintabu = min(mintabu, tabu_list_couple[remove][add]);
		mintabu = min(mintabu, tabu_list_couple[add][remove]);
	}
	else if (paraments.get_tabu_type() == "double") {//待思考
		mintabu = min(mintabu, tabu_list_serve[add]);
		mintabu = min(mintabu, tabu_list_user[remove]);
	}
	else {
		printf("no this tabu type!\n");
	}
	return mintabu;
}
void tabu::clear(int n)
{
	if (paraments.get_tabu_type() == "couple") {
		tabu_list_couple.resize(n + 1, vector<int>(n + 1, 0));
	}
	else if (paraments.get_tabu_type() == "double") {//待思考
		tabu_list_serve.resize(n + 1, 0);
		tabu_list_user.resize(n + 1, 0);
	}
	else {
		printf("no this tabu type!\n");
	}
}
//serveS m(100,10);
//node point(100);
void P_center_action::set_opt() {
	bestopt["pmed1"] = 127;
	bestopt["pmed2"] = 98;
	bestopt["pmed3"] = 93;
	bestopt["pmed4"] = 74;
	bestopt["pmed5"] = 48;
	bestopt["pmed6"] = 84;
	bestopt["pmed7"] = 64;
	bestopt["pmed8"] = 55;
	bestopt["pmed9"] = 37;
	bestopt["pmed10"] = 20;
	bestopt["pmed11"] = 59;
	bestopt["pmed12"] = 51;
	bestopt["pmed13"] = 36;
	bestopt["pmed14"] = 26;
	bestopt["pmed15"] = 18;
	bestopt["pmed16"] = 47;
	bestopt["pmed17"] = 39;
	bestopt["pmed18"] = 28;
	bestopt["pmed19"] = 18;
	bestopt["pmed20"] = 13;
	bestopt["pmed21"] = 40;
	bestopt["pmed22"] = 38;
	bestopt["pmed23"] = 22;
	bestopt["pmed24"] = 15;
	bestopt["pmed25"] = 11;
	bestopt["pmed26"] = 38;
	bestopt["pmed27"] = 32;
	bestopt["pmed28"] = 18;
	bestopt["pmed29"] = 13;
	bestopt["pmed30"] = 9;
	bestopt["pmed31"] = 30;
	bestopt["pmed32"] = 29;
	bestopt["pmed33"] = 15;
	bestopt["pmed34"] = 11;
	bestopt["pmed35"] = 30;
	bestopt["pmed36"] = 27;
	bestopt["pmed37"] = 15;
	bestopt["pmed38"] = 29;
	bestopt["pmed39"] = 23;
	bestopt["pmed40"] = 13;
	bestopt["tsp.u1060.p10"] = 227308;
	bestopt["tsp.u1060.p20"] = 158080;
	bestopt["tsp.u1060.p30"] = 120777;
	bestopt["tsp.u1060.p40"] = 102056;
	bestopt["tsp.u1060.p50"] = 90492;
	bestopt["tsp.u1060.p60"] = 78117;
	bestopt["tsp.u1060.p70"] = 71075;
	bestopt["tsp.u1060.p80"] = 65216;
	bestopt["tsp.u1060.p90"] = 60787;
	bestopt["tsp.u1060.p100"] = 57001;
	bestopt["tsp.u1060.p110"] = 53884;
	bestopt["tsp.u1060.p120"] = 51027;
	bestopt["tsp.u1060.p130"] = 49965;
	bestopt["tsp.u1060.p140"] = 45246;
	bestopt["tsp.u1060.p150"] = 44701;
	bestopt["tsp.rl1323.p10"] = 307730;
	bestopt["tsp.rl1323.p20"] = 201640;
	bestopt["tsp.rl1323.p30"] = 163150;
	bestopt["tsp.rl1323.p40"] = 135236;
	bestopt["tsp.rl1323.p50"] = 118727;
	bestopt["tsp.rl1323.p60"] = 106301;
	bestopt["tsp.rl1323.p70"] = 97193;
	bestopt["tsp.rl1323.p80"] = 89506;
	bestopt["tsp.rl1323.p90"] = 83200;
	bestopt["tsp.rl1323.p100"] = 78970;
	bestopt["tsp.u1817.p10"] = 45791;
	bestopt["tsp.u1817.p20"] = 30901;
	bestopt["tsp.u1817.p30"] = 24099;
	bestopt["tsp.u1817.p40"] = 20945;
	bestopt["tsp.u1817.p50"] = 18491;
	bestopt["tsp.u1817.p60"] = 16264;
	bestopt["tsp.u1817.p70"] = 14811;
	bestopt["tsp.u1817.p80"] = 13680;
	bestopt["tsp.u1817.p90"] = 12951;
	bestopt["tsp.u1817.p100"] = 12699;
	bestopt["tsp.u1817.p110"] = 10925;
	bestopt["tsp.u1817.p120"] = 10776;
	bestopt["tsp.u1817.p130"] = 10775;
	bestopt["tsp.u1817.p140"] = 10161;
	bestopt["tsp.u1817.p150"] = 9244;
	bestopt["tsp.pcb3038.p10"] = 72854;
	bestopt["tsp.pcb3038.p20"] = 49304;
	bestopt["tsp.pcb3038.p30"] = 39350;
	bestopt["tsp.pcb3038.p40"] = 33642;
	bestopt["tsp.pcb3038.p50"] = 29820;
	bestopt["tsp.pcb3038.p100"] = 20663;
	bestopt["tsp.pcb3038.p150"] = 16477;
	bestopt["tsp.pcb3038.p200"] = 14090;
	bestopt["tsp.pcb3038.p250"] = 12278;
	bestopt["tsp.pcb3038.p300"] = 11525;
	bestopt["tsp.pcb3038.p350"] = 10481;
	bestopt["tsp.pcb3038.p400"] = 9751;
	bestopt["tsp.pcb3038.p450"] = 8896;
	bestopt["tsp.pcb3038.p500"] = 8500;

	mybetteropt["tsp.u1060.p20"] = 158079;
	mybetteropt["tsp.u1060.p60"] = 78116;
	mybetteropt["tsp.u1060.p110"] = 53883;
	mybetteropt["tsp.u1060.p150"] = 44700;
	mybetteropt["tsp.rl1323.p10"] = 307729;
	mybetteropt["tsp.rl1323.p20"] = 201639;
	mybetteropt["tsp.rl1323.p50"] = 118726;
	mybetteropt["tsp.u1817.p10"] = 45790;
	mybetteropt["tsp.u1817.p80"] = 13679;//must better
	mybetteropt["tsp.u1817.p130"] = 10774;
	mybetteropt["tsp.u1817.p140"] = 10160;//must better
	mybetteropt["tsp.pcb3038.p20"] = 49303;
	return;

}
P_center_action::P_center_action(string instance_name,int n, int p, Algorithm_paraments paraments, szx::Arr2D<szx::Length>Graph) :m(n, p), point(n), M(n + 1), G(n + 1, vector<int>(n + 1)), tabu_info(n,paraments) {//m,point是自己定义的
	P_center_action::instname = instance_name;
	P_center_action::n = n;
	P_center_action::p = p;
	P_center_action::paraments = paraments;
	//P_center_action::G = Graph;
	//G.resize(n + 1, vector<int>(n + 1, 0));


	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			G[i][j] = Graph.at(i-1,j-1);
	P_center_action::set_opt();

	return;
}

int P_center_action::caculate_opt() {
	int opt = 0;
	for (int i = 1; i <= n; i++) {
		opt = std::max(point.D_first[i], opt);
	}
	return opt;
}
void P_center_action::show_M() {
	for (int i = 1; i <= m.len; i++)
		printf("M[%d]=%d ", m.S[i], M[m.S[i]]);
	printf("\n");
}
int P_center_action::select_maxlen_edge(int &user, int &serve) {// 1为用户节点 2为服务节点
	int maxlen = 0;
	int maxcount = 0;
	for (int i = 1; i <= n; i++) {
		if (maxlen < point.D_first[i]) {
			maxlen = point.D_first[i];
			user = i;
			serve = point.F_first[i];
			maxcount = 1;
		}
		else if (maxlen == point.D_first[i]) {
			maxcount++;
			if (rand() % maxcount == 0) {
				user = i;
				serve = point.F_first[i];
			}
		}
	}
	//printf("maxedge:%d-%d maxlen=%d\n", user, serve, maxlen);
	return maxlen;
}
int P_center_action::select_Nk(int i) {
	int count = 0;
	int distance = point.D_first[i];
	int ret = 0;
	for (int k = 1; k <= n; k++)
		if (G[i][k] < distance) {
			count++;
			if (rand() % count == 0)
				ret = k;
		}
	return ret;
}
vector<int> P_center_action::give_Nwk(int w) {
	int distance = point.D_first[w];
	//vector<int>ret1(0, 0);
	vector<int>ret(0, 0);
	map<int, vector<int>>retmap;

	for (int k = 1; k <= n; k++)
		if (G[w][k] < distance) {
			//ret1.push_back(k);
			if (retmap.find(G[w][k]) != retmap.end())
				retmap[G[w][k]].push_back(k);
			else
				retmap[G[w][k]] = vector<int>(1, k);
			//retmap[G[w][k]].push_back(k);
		}

	map<int, vector<int>>::iterator iter;
	int k = paraments.get_k()+rand()%10;//引入疏散性
	int nowlen = 0;

	for (iter = retmap.begin(); iter != retmap.end(); iter++) {
		nowlen += int(iter->second.size());
		ret.insert(ret.end(), iter->second.begin(), iter->second.end());
		if (nowlen >= k)
			break;
	}
	/*cout << "ret1: ";
	for (auto i : ret1)
		cout <<"["<< i <<": "<<G[w][i]<<"]";
	cout << endl;

	cout << "ret: ";
	for (auto i : ret)
		cout << i << ' ';
	cout << endl<<endl;*/
	
	return ret;
}
void P_center_action::add_facility(int newserve) {
	m.addF(newserve);
	for (int i = 1; i <= n; i++) {
		if (G[newserve][i] <= point.D_first[i]) {
			point.D_second[i] = point.D_first[i];
			point.F_second[i] = point.F_first[i];
			point.D_first[i] = G[newserve][i];
			point.F_first[i] = newserve;
		}
		else if (G[newserve][i] < point.D_second[i] || (G[newserve][i] == point.D_second[i] && rand() % 2 == 0)) {
			point.D_second[i] = G[newserve][i];
			point.F_second[i] = newserve;
		}
	}
	return;
}
int P_center_action::find_next(int user) {
	int count = 0;
	int mindistance = INT_MAX;
	int next_serve = 0;
	for (int i = 1; i <= m.len; i++) {
		int serve = m.S[i];
		if (serve != point.F_first[user] && serve != point.F_second[user]) {
			if (mindistance > G[user][serve]) {
				mindistance = G[user][serve];
				next_serve = serve;
				count = 1;
			}
			else if (mindistance == G[user][serve]) {
				count++;
				if (rand() % count == 0)
					next_serve = serve;
			}
		}
	}
	return next_serve;
}
void P_center_action::remove_facility(int oldserve) {
	m.deleteF(oldserve);
	for (int i = 1; i <= n; i++) {
		if (point.F_first[i] == oldserve) {
			point.D_first[i] = point.D_second[i];
			point.F_first[i] = point.F_second[i];
			int Fnew = find_next(i);
			point.D_second[i] = G[i][Fnew];
			point.F_second[i] = Fnew;
		}
		else if (point.F_second[i] == oldserve) {
			int Fnew = find_next(i);
			point.D_second[i] = G[i][Fnew];
			point.F_second[i] = Fnew;
		}
	}
	return;
}
void P_center_action::caculate_M(int newserve) {
	for (int i = 1; i <= m.len; i++)
		M[m.S[i]] = 0;
	for (int v = 1; v <= n; v++)
		//if (m.exist(v) == false) {//为什么要加这一句强调是对用户节点而不是对全部节点
	{
		int nowserve = point.F_first[v];
		int secondserve = point.F_second[v];
		int nowdistance = point.D_first[v];
		int seconddistance = point.D_second[v];
		//M[nowserve] = max(M[nowserve], min(seconddistance, G[v][newserve]));
		M[nowserve] = max(M[nowserve], seconddistance);
	}
	/*printf("------------------\nnewserve:%d\n",newserve);
	m.show();
	show_M();
	printf("-------------\n");*/
	return;
}
void P_center_action::BEGIN() {
	srand(paraments.get_seed());//随机种子

	int firstp = rand() % n + 1;
	int maxlen = 0;
	int secondp = 0;
	int maxcount = 0;
	for (int i = 1; i <= n; i++) {
		if (maxlen < G[firstp][i]) {
			maxlen = G[firstp][i];
			secondp = i;
			maxcount = 1;
		}
		else if (maxlen == G[firstp][i]) {
			maxcount++;
			if (rand() % maxcount == 0)
				secondp = i;
		}
	}


	for (int i = 1; i <= n; i++) {
		if (G[i][firstp] < G[i][secondp]) {
			point.D_first[i] = G[i][firstp];
			point.D_second[i] = G[i][secondp];
			point.F_first[i] = firstp;
			point.F_second[i] = secondp;
		}
		else {
			point.D_first[i] = G[i][secondp];
			point.D_second[i] = G[i][firstp];
			point.F_first[i] = secondp;
			point.F_second[i] = firstp;
		}
	}
	//printf("firstp %d secondp %d\n", firstp, secondp);
	//showpoint();
	m.addF(firstp);
	m.addF(secondp);
	int i, j;
	for (int cc = 3; cc <= p; cc++) {
		int opt = select_maxlen_edge(i, j);//i为用户节点j为服务节点
		int newserve = select_Nk(i);
		//printf("newserve=%d\n", newserve);
		add_facility(newserve);
		//showpoint();
	}
	//for (int cc = p; cc >= 3; cc--) {
	//	int randp = m.randget();
	//	printf("deleteserve=%d\n", randp);
	//	remove_facility(randp);
	//	showpoint();
	//}测试remove_facility代码
	return;
}

int P_center_action::find_pair(int& add, int& remove, int t, int best_opt) {
	add = 0;
	remove = 0;
	int import_user, import_serve;
	int C = select_maxlen_edge(import_user, import_serve);
	//printf("C=%d\n",C);
	vector<int>Nwk = give_Nwk(import_user);
	if (Nwk.size() == 0) {
		printf("can't find Nwk\n");
		return -1;
	}
	int paircount = 0;
	C = INT_MAX;
	int mintabu = INT_MAX;
	for (auto newserve : Nwk) {
		add_facility(newserve);
		caculate_M(newserve);
		int opt = caculate_opt();
		for (int i = 1; i <= m.len; i++) {
			int f = m.S[i];
			if (f == newserve)
				continue;//避免加入和删除同一个节点；
			if (tabu_info.whether_tabu(newserve,f,t)) {

				if (M[f] < C) {
					C = M[f];
					add = newserve;
					remove = f;
					paircount = 1;
				}
				else if (M[f] == C) {
					paircount++;
					if (rand() % paircount == 0) {
						add = newserve;
						remove = f;
					}
				}
			}
			else if (best_opt > max(opt, M[f])) {
				if (M[f] < C) {
					C = M[f];
					add = newserve;
					remove = f;
					paircount = 1;
				}
				else if (M[f] == C) {
					paircount++;
					if (rand() % paircount == 0) {
						add = newserve;
						remove = f;
					}
				}
			}
			else {
				mintabu = tabu_info.get_mintabu(newserve, f, mintabu);
			}

		}

		remove_facility(newserve);

	}




	if (add == 0) {

		printf("can't find couple not in tabu!\n");
		return mintabu;
	}
	//printf("add=%d remove=%d tabu=%d\n", add, remove,tabu_list[remove][add]);
	return -1;
}
int P_center_action::neighbour_action(int &add, int &remove, int t, int best_opt) {
	add = 0;
	remove = 0;
	int mintabu = find_pair(add, remove, t, best_opt);
	if (add == 0 || add == remove || remove == 0)
		return mintabu;
	add_facility(add);
	remove_facility(remove);
	//int opt = caculate_opt();
	//printf("swap:%d %d,opt=%d   \n------------------------------", add, remove, opt);

	return -1;
}


//search part
vector<int> P_center_action::search(vector<int>& opt_serves) {
	BEGIN();
	int add = 0;
	int remove = 0;
	int opt = INT_MAX;
	int t;
	int itera_use_opt;


	const int rewardvalue = paraments.get_reward_value();
	const int periodvalue = paraments.get_period_threshold();
	int lasttime = 0;
	bool optchange = true;//自适应total_iteration参数

	int sum_step = paraments.get_total_iterations();

	time_t start, stop;
	start = time(NULL);


	for (t = 1; t <= sum_step; t++) {
		int mintabu = neighbour_action(add, remove, t, opt);


		if (add == 0) {
			sum_step += mintabu - t;
			t = mintabu;
			continue;
		}
		if (tabu_info.whether_tabu(add,remove,t)) {
		}
		else {
			//printf("tabu! add=%d remove=%d\n", add, remove);
		}
		tabu_info.modify_tabu(add, remove, t);
		




		if (opt > caculate_opt()) {
			opt = caculate_opt();
			printf("t=%d opt=%d bestopt=%d tabu_step=%d total_iterations=%d\n", t, opt, bestopt[instname], paraments.get_tabu_step(), paraments.get_total_iterations());
			opt_serves = m.get_serves();
			itera_use_opt = t - 1;
			optchange = true;
			//show_M();
		}

		if (opt <= (bestopt[instname] * 1.02) && (optchange == true)) {
			optchange = false;
			int peroid = t - lasttime;
			if (peroid > periodvalue) {
				lasttime = t;
				sum_step += rewardvalue;
			}

		}

		if (mybetteropt.find(instname) == mybetteropt.end()) {
			if (opt == bestopt[instname])
				break;
		}
		else {
			if (opt == mybetteropt[instname])
				break;
		}

		if (1) {
			stop = time(NULL);
			if (stop - start >= paraments.get_time_limits())//60s*30min
				break;
		}
		//break;
	/*printf("%d->%d\n",add,remove);
	m.show();*/
	//		show_M();

	}
	if (opt == bestopt[instname])
		printf("-----------------get paper's best solution------------------------total_iteration=%d-----------------------\n", t - 1);
	else if (opt < bestopt[instname])
		printf("---------------get better solution than paper---------------------total_iteration=%d-----------------------\n", t - 1);
	else
		printf("------------------not get best solution---------------------------total_iteration=%d-----------------------\n", t - 1);
	reset();
	std::sort(opt_serves.begin(), opt_serves.end());
	vector<int> info;
	info.push_back(opt);
	info.push_back(t - 1);//run_total_iteration
	info.push_back(itera_use_opt);//iteration_use_to_get_opt
	return info;
}
void P_center_action::reset() {
	m.clear();
	tabu_info.clear(n);
}

void autosearch::outmylog(ofstream outFile,Algorithm_paraments a, vector<int>runinfo)
{
	
	
}

void autosearch::search(string instance_name, int n, int p, szx::Arr2D<szx::Length>Graph)
{
	ofstream outFile;
	outFile.open("hyjlog.csv", ios::app); // 记录测试数据
	if (!outFile) {
		cout << "--------------file open failed!!--------------" << endl;
		return;
	}
	outFile << "name,n,p,time,seed,tabu_type,iteration,iter_get_opt,tabu_step,k,opt_ans" << endl;

	for(double step=1000;step<100000;step*=1.25)
		for (double k = 10; k<=100; k*=1.12) 
			for(int seed=1;seed<=10000;seed*=100)
		{

			Algorithm_paraments paraments;
			paraments.set_period_threshold(n*(n - p) / 30);
			paraments.set_reward_value(n*(n - p) / 50);
			paraments.set_tabu_step(int(step));
			paraments.set_total_iterations(n*(n - p));
			paraments.set_tabu_type("couple");

			paraments.set_seed(seed);
			//paraments.set_seed((unsigned)time(NULL));
		
			paraments.set_k(int(k));
			paraments.set_time_limits(30);//单位：s

			//cout << aux.adjMat[0][0] << endl;
			P_center_action A(instance_name, n, p, paraments, Graph);

			vector<int>opt_serves;
			vector<int> info = A.search(opt_serves);

			Algorithm_paraments &a = paraments;
			outFile <<instance_name<<','<<n<<","<<p<<","<< a.get_time_limits() << ',' << a.get_seed() << ',' << a.get_tabu_type() << "," << info[1] << ',' \
				<< info[2] << "," << a.get_tabu_step() << ',' << a.get_k() << ',' << info[0] << endl;

		}
	

	outFile.close();

	cout << "aotu search has done!\n";
}

vector<int> autosearch::run(string instance_name, int n, int p, szx::Arr2D<szx::Length> Graph)
{
	ofstream outFile;
	outFile.open("hyjlog.csv", ios::app); // 记录测试数据
	if (!outFile) {
		cout << "--------------file open failed!!--------------" << endl;
		return vector<int>(0,0);
	}
	outFile << "name,n,p,time,seed,tabu_type,iteration,iter_get_opt,tabu_step,k,opt_ans,run!!!" << endl;


	Algorithm_paraments paraments;
	paraments.set_period_threshold(n*(n - p) / 30);
	paraments.set_reward_value(n*(n - p) / 50);
	paraments.set_tabu_step(3000);
	paraments.set_total_iterations(n*(n - p));
	paraments.set_tabu_type("couple");
	//paraments.set_seed((unsigned)time(NULL));
	paraments.set_seed(0);
	paraments.set_k(40);
	paraments.set_time_limits(60*10);//单位：s

	//cout << aux.adjMat[0][0] << endl;
	P_center_action A(instance_name, n, p, paraments, Graph);
	


	vector<int>opt_serves;
	vector<int> info = A.search(opt_serves);

	Algorithm_paraments &a = paraments;
	outFile << instance_name << ',' << n << "," << p << "," << a.get_time_limits() << ',' << a.get_seed() << ',' << a.get_tabu_type() << "," << info[1] << ',' \
		<< info[2] << "," << a.get_tabu_step() << ',' << a.get_k() << ',' << info[0] << endl;
	return opt_serves;
}



