#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include <algorithm>

double operator*(const std::vector<double>& a, const std::vector<double> b) {
    if (a.size() != b.size()) {
        throw std::invalid_argument("Vectors must be the same size for dot product.");
    }

    double out {0.0};
    for (size_t i = 0; i < a.size(); i++) {
        out += a[i] * b[i];
    }
    return out;
}


class linearRegression
{
private:
    std::vector<double> theta;
    double lr;
public:
    linearRegression(int feature_size, double _lr) : lr(_lr) {
        theta.resize(feature_size);
    }
    double predict(std::vector<double>& x) {
        return theta * x;
    }
    void update(std::vector<double>& x, double y) {
        for (size_t i=0; i<theta.size(); i++) {
            theta[i] += lr * (y-predict(x))*x[i];
        }
    }
    void SGD(std::vector<std::vector<double>>& features, std::vector<double>& targets) {
        for (size_t i=0; i<features.size(); i++) {
            update(features[i], targets[i]);
        }
    }
    void BGD(std::vector<std::vector<double>>& features, std::vector<double>& targets) {
        for (size_t j=0; j<theta.size(); j++) {
            double sum {0};
            for (size_t i=0; i<features.size(); i++) {
                sum += (targets[i]-predict(features[i])) * features[i][j];
            }
            theta[j] += lr * sum;
        }
    }
    double mse(std::vector<std::vector<double>>& features, std::vector<double>& targets) {
        double out {0};
        for (size_t i=0; i<features.size(); i++) {
            out += (targets[i]-predict(features[i])) * (targets[i]-predict(features[i]));
        }
        out = out / features.size();
        return out;
    }
};

void read_csv(std::vector<std::vector<double>>& features, std::vector<double>& targets, std::string path) {
    std::ifstream file(path);

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        std::vector<double> x {1};

        std::getline(ss, cell, ',');
        targets.push_back(std::stod(cell)/(13.3e6));

        for (int i=0; i<4; i++) {
            std::getline(ss, cell, ',');
            x.push_back(std::stod(cell)/(16.2e3));
        }
        for (int i=0; i<5; i++) {
            std::getline(ss, cell, ',');
            x.push_back((cell=="yes"));
        }

        std::getline(ss, cell, ',');
        x.push_back(std::stod(cell));

        std::getline(ss, cell, ',');
        x.push_back((cell=="yes"));

        features.push_back(x);

    }
    file.close();

}

int main() {

    double TEST_SPLIT {0.2};

    std::vector<std::vector<double>> features;
    std::vector<double> targets;

    read_csv(features, targets, "Housing.csv");
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(features.begin(), features.end(), g);
    std::shuffle(targets.begin(), targets.end(), g);


    std::vector<std::vector<double>> test_features(features.end()-TEST_SPLIT*features.size(), features.end());
    std::vector<double> test_targets(targets.end()-TEST_SPLIT*targets.size(), targets.end());

    features.resize((1-TEST_SPLIT)*features.size());
    targets.resize((1-TEST_SPLIT)*targets.size());


    linearRegression model(features[0].size(), 1e-6);

    for (int i=0; i<=500; i++) {
        model.SGD(features, targets);
        std::cout << model.mse(test_features, test_targets) << "  -----------  Iteration: " << i << std::endl;
    }

    std::cout << model.predict(test_features[100]) << "  -----------  " << test_targets[100] << std::endl;

    std::cout << model.mse(test_features, test_targets) << std::endl;
    return 0;
}