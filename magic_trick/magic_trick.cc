#include <iostream>
#include <vector>

const int MAX_CARDS = 16;
const int NUM_COL = 4;

int __ifHasSameEle(const std::vector<int>& v1, const std::vector<int>& v2, int& ans)
{
    int cnt = 0;
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            if (v1[i] == v2[j]) {
                cnt++;
                ans = v1[i];
            }
        }
    }
    return cnt;
}

int main(void)
{
    int cnt;

    std::cin >> cnt;
    for (int k = 1; k <= cnt; ++k) {
        int answer1, answer2;

        std::cin >> answer1;
        int arrange1[MAX_CARDS];
        for (int i = 0; i < MAX_CARDS; ++i) {
            int tmp;
            std::cin >> tmp;
            arrange1[i] = tmp;
        }

        std::cin >> answer2;
        int arrange2[MAX_CARDS];
        for (int i = 0; i < MAX_CARDS; ++i) {
            int tmp;
            std::cin >> tmp;
            arrange2[i] = tmp;
        }

        std::vector<int> range1, range2;
        for (int i = NUM_COL * (answer1 - 1); i < NUM_COL * answer1; ++i) {
            range1.push_back(arrange1[i]);
        }
        for (int i = NUM_COL * (answer2 - 1); i < NUM_COL * answer2; ++i) {
            range2.push_back(arrange2[i]);
        }

        int ans;
        int rst = __ifHasSameEle(range1, range2, ans);
        if (rst == 1) {
            std::cout << "Case #" << k << ": " << ans << std::endl;
        } else if (rst == 0) {
            std::cout << "Case #" << k << ": " << "Volunteer cheated!" << std::endl;
        } else {
            std::cout << "Case #" << k << ": " << "Bad magician!" << std::endl;
        }
    }
}