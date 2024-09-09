#include <iostream>
#include <vector>
using namespace std;

int min_performances(int groups[], int N) {
    int count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0;
    for (int i = 0; i < N; i++) {
    	int group = groups[i];
//    	cout << group << endl;
        if (group == 1) count_1++;
        else if (group == 2) count_2++;
        else if (group == 3) count_3++;
        else if (group == 4) count_4++;
    }

    // Buoc 1: Ghép tat ca các nhóm 4 nguoi (moi nhóm này chiem 1 luot)
    int performances = count_4;

    // Buoc 2: Ghép các nhóm 3 ngu?i v?i nhóm 1 ngu?i
    int min_3_1 = min(count_3, count_1);
    performances += min_3_1;
    count_3 -= min_3_1;
    count_1 -= min_3_1;

    // Buoc 3: Ghép các nhóm 3 nguoi còn lai (moi nhóm này chiem 1 lut)
    performances += count_3;

    // Buoc 4: Ghép các nhóm 2 nguoi lai voi nhau hoac ghép voi 2 nhóm 1 nguoi
    performances += count_2 / 2;
    count_2 %= 2;
    if (count_2 > 0) {
        if (count_1 >= 2) {
            performances += 1;
            count_1 -= 2;
        } else {
            performances += 1;
//            count_1 = 0;
        }
    }

    // Buoc 5: Ghép các nhóm 1 nguoi còn lai
    performances += count_1 / 4;
    if (count_1 % 4 > 0) {
        performances += 1;
    }

    return performances;
}

int main() {
    
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int N;
    cin  >> N;
    int groups[N];
    for (int i = 0; i < N; i++) {
        cin >> groups[i];
    }

    int result = min_performances(groups, N);

    cout << result;

    return 0;
}

