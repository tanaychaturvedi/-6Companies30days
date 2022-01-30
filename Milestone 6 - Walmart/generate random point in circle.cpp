class Solution {
    double R,X,Y;
    
    double random()
    {
         return ((double) rand() / (RAND_MAX));
    }
    
public:
    Solution(double radius, double x_center, double y_center) : R(radius) , X(x_center) , Y(y_center)
    {
        
    }
    
    vector<double> randPoint() {
        double len = sqrt(random()) * R;
        double theta = 2 * M_PI * random();
        
        double a = X + (len * cos(theta));
        double b = Y + (len * sin(theta));
        
        return {a,b};
    }
};
