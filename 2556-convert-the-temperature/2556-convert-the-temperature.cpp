class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> res;
        double kelvin = (double)((double)(9*celsius/5) + (double)32);
        double fahrenheit = (double)(celsius + (double)273.15);
        res.push_back(fahrenheit);
        res.push_back(kelvin);
        return res;
    }
};