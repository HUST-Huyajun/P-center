#include"neighbor_move.h"
#include "Utility.h"
#include "Common.h"

#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
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
	bestopt["tsp.u1060.p70"] = 71076;
	bestopt["tsp.u1060.p80"] = 65216;
	bestopt["tsp.u1060.p90"] = 60788;
	bestopt["tsp.u1060.p100"] = 57001;
	bestopt["tsp.u1060.p110"] = 53884;
	bestopt["tsp.u1060.p120"] = 51028;
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
	bestopt["tsp.u1817.p40"] = 20946;
	bestopt["tsp.u1817.p50"] = 18491;
	bestopt["tsp.u1817.p60"] = 16265;
	bestopt["tsp.u1817.p70"] = 14811;
	bestopt["tsp.u1817.p80"] = 13680;
	bestopt["tsp.u1817.p90"] = 12954;
	bestopt["tsp.u1817.p100"] = 12701;
	bestopt["tsp.u1817.p110"] = 10925;
	bestopt["tsp.u1817.p120"] = 10778;
	bestopt["tsp.u1817.p130"] = 10775;
	bestopt["tsp.u1817.p140"] = 10161;
	bestopt["tsp.u1817.p150"] = 10160;
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
	return;

}
P_center_action::P_center_action(string instance_name,int n, int p, int tabu_parament_R, int tabu_sum_step, szx::Arr2D<szx::Length>Graph) :m(n, p), point(n), M(n + 1), G(n + 1, vector<int>(n + 1)), tabu_list(n + 1, vector<int>(n + 1, 0)) {//m,point是自己定义的
	P_center_action::instname = instance_name;
	P_center_action::n = n;
	P_center_action::p = p;
	P_center_action::R = tabu_parament_R;
	P_center_action::sum_step = tabu_sum_step;
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
	vector<int>ret(0, 0);
	for (int k = 1; k <= n; k++)
		if (G[w][k] < distance) {
			ret.push_back(k);
		}
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
			if (tabu_list[f][newserve] <= t) {//加入禁忌 tabu_list[remove][add]

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
				mintabu = min(mintabu, tabu_list[f][newserve]);
				mintabu = min(mintabu, tabu_list[newserve][f]);
			}

		}

		remove_facility(newserve);

	}




	if (add == 0) {

		printf("wrong!\n");
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
int P_center_action::get_tt() {
	return R + rand() % 10 + 1;
}
int P_center_action::search(vector<int>& opt_serves) {
	BEGIN();
	int add = 0;
	int remove = 0;
	int opt = INT_MAX;
	for (int t = 1; t <= sum_step; t++) {
		int mintabu = neighbour_action(add, remove, t, opt);


		if (add == 0) {
			sum_step += mintabu - t;
			t = mintabu;
			continue;
		}
		if (tabu_list[remove][add] <= t) {
		}
		else {
			//printf("tabu! add=%d remove=%d\n", add, remove);
		}
		int tabu_step = get_tt() + t;
		tabu_list[remove][add] = tabu_step;
		tabu_list[add][remove] = tabu_step;




		if (opt > caculate_opt()) {
			opt = caculate_opt();
			printf("t=%d opt=%d bestopt=%d\n", t, opt, bestopt[instname]);
			opt_serves = m.get_serves();
			//show_M();
		}

		if (opt == bestopt[instname]) {
			//m.show();
			//int dui = 0;
			//for (int v = 1; v <= n; v++) {
			//	int distance = INT_MAX;
			//	int sserve = 0;
			//	for (int index = 1; index <= p; index++) {
			//		int serve = m.S[index];
			//		if (distance > G[serve][v]) {
			//			distance = G[serve][v];
			//			sserve = serve;
			//		}


			//	}
			//	//printf("distance<user%d,serve%d>=%d\n",v,sserve,distance);
			//	dui = max(dui, distance);
			//}
			//printf("dui=%d\n", dui);
			//m.show();

			printf("---------------------------------get best solve---------------------------------\n");
			break;
		}
		//break;
	/*printf("%d->%d\n",add,remove);
	m.show();*/
	//		show_M();

	}

	return opt;
}

void P_center_action::reset() {
	m.clear();
	tabu_list.resize(n + 1, vector<int>(n + 1, 0));

}