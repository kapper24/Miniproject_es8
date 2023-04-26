#include<eigen

class KalmanFilter
{
private:
    float g{9.82};
    float frictioncoefficient{0.3196719489154};
    float theta{0.407528515};
    VectorXf x{{0},{0},{0}};
    MatrixXf A{ {{1}, {deltaT}, {2*deltaT^2}},
                {{0}, {1},      {deltaT}  },
                {{0}, {0},      {0}       }};
    VectorXf B{{0},{0},{g *(sin(theta)-cos(theta)*frictioncoefficient)}}
    float U{1};
    MatrixXf Covariance;
    MatrixXf system_noise{{1,0,0},{0,1,0},{0,0,1}};
public:
    void predict();
    void update(Vectorxf measurement, MatrixXf R, MatrixXf C);
    VectorXf GetCurrentState(){return x}

};

void KalmanFilter::predict(VectorXf current_state)
{
 x = A*x;
 x = x+B;   
 Covariance = A*Covariance;
 Covariance = Covariance*A';
 Covariance = Covariance + Systemnoise;
}

void KalmanFilter::update(VectorXf current_state, Vectorxf measurement, MatrixXf S, MatrixXf C)
{
    R = Covar * C;
    R = R * S.inverse();
    VectorXf x_measurement_estimate = C*x;
    VectorXf v = measurement - x_measurement_update;
    VectorXf update_vector = R*v;
    x = x+update_vector;
    MatrixXf covariance_update = R * C;
    covariance_update = covariance_update * Covariance;
    Covariance = Covariance-covariance_update;

}