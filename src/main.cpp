#include <iostream>
#include <random>
#include <cmath>
#include<algorithm>
#include<vector>
#include<fstream>
#include<chrono>
using namespace std;

double N(double x){
    return 0.5 * (1 + erf(x / sqrt(2)));
}

double black_scholes_call(double S0,double K,double r,double sigma,double T)
{
    double d1 = (log(S0/K) + (r+0.5*sigma*sigma)*T) / (sigma*sqrt(T));
    double d2 = d1 - sigma*sqrt(T);
    double price = S0*N(d1) - K*exp(-r*T)*N(d2);
    return price;
}

int main(){
    random_device rd;
    mt19937 generator(rd());
    normal_distribution<double>normal_dist(0.0, 1.0);
    double S0 = 100;
    double K = 100;
    double r = 0.05;
    double T = 1.0;
    ofstream file("../result/convergence.csv");
    if (!file)
    {
        cout<<"Error opening file\n";
    }
    file<<"Sigmas,Simulations,MC_Price,BS_Price,Error,Time_ms\n";
    vector<double>sigmas = {0.1,0.2,0.3,0.4};
    vector<int>num_simulations = {1000,5000,10000,50000,100000};
    for (auto sigma : sigmas)
    {
        double bs_price = black_scholes_call(S0,K,r,sigma,T);
        for (auto x : num_simulations)
        {
            auto start = chrono::high_resolution_clock::now();
            double sum_payoff = 0;
            for(int i=0;i<x;i++)
            {
                double Z = normal_dist(generator);
                double drift = (r - 0.5*sigma*sigma)*T;
                double diffusion = sigma*sqrt(T)*Z;
                double ST = S0 * exp(drift + diffusion);
                double payoff = max(ST-K, 0.0);
                sum_payoff += payoff;
            }
            double average_payoff = sum_payoff/(double)x;
            double mc_price = exp(-r*T) * average_payoff;
            double error = abs(mc_price-bs_price);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> elapsed = end - start;
            file<<sigma<<","<<x<<","<<mc_price<<","<<bs_price<<","<<error<<","<<elapsed.count()<<"\n";
            // cout<<"Simulations: "<<x<<endl;
            // cout<<"Monte Carlo Price: "<<mc_price<<endl;
            // cout<<"Black Scholes Price: "<<bs_price<<endl;
            // cout<<"Error: "<<error<<endl;
            // cout<<"Elapsed (ms): "<<elapsed.count()<<endl;
            // cout<<"----------------"<<endl;       
        }
    }
    file.close();
    return 0;
}