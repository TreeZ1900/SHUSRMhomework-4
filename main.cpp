#include <iostream>
#include <vector>
#include <algorithm> // sort, all_of, for_each
using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> scores(n);
    cout << "Enter scores:\n";
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    // 1. 使用 Lambda 对分数进行降序排序
    sort(scores.begin(), scores.end(),
    [](int a,int b) {return a > b;});
    //这里的 return 并非直接 “确定排序类型”，而是通过返回的布尔值告诉 sort 函数 “两个元素应该如何排序”。
    //默认排序是升序，Lambda 表达式在这里是为了实现降序排序这个特殊需求
         /* TODO: Lambda 表达式，按分数从高到低排序 */
    //lambda 表达式的优势在于简化代码、避免定义额外的命名函数，尤其适合这种简单的逻辑判断
    //bool allPassed = std::all_of(scores.begin(), scores.end(), isPassed);是等价的

    // 2. 使用 Lambda 判断是否所有学生分数 >= 60
    bool allPassed = all_of(scores.begin(), scores.end(),
        //all_of：如果所有元素都满足条件则返回 true，否则返回 false
        [](int score) {return score >= 60;});
        /* TODO: Lambda 表达式，判断分数是否 >= 60 */

    // 3. 如果不是所有人都及格，则使用 Lambda 给低于 60 分的加 5 分
    if (!allPassed) {
        for_each(scores.begin(), scores.end(),
        //for_each：遍历容器中 [begin(), end()) 范围内的所有元素，并对每个元素执行第三个参数指定的操作（这里是 Lambda 表达式）
          [](int& score) {
              if (score<60)
              score+=5; });
        /* TODO: Lambda 表达式，分数 < 60 时加 5 分 */
    }

    // 输出排序后的成绩
    cout << "\nSorted scores:\n";
    for (int score : scores) {
        cout << score << " ";
    }
    cout << "\nAll students passed: " << (allPassed ? "Yes" : "No") << endl;

    return 0;
}