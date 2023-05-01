class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        double sum = 0;
        for (int i = 0; i < salary.size(); i++) {
            sum += salary[i];
        }
        double min=salary[0];
        double max=salary[salary.size()-1];
        return (sum - min - max) / (salary.size() - 2);
    }
};