class Sampling
{
public:
    Sampling(long sampling_Time);

    [[nodiscard]] bool Sample();

    int GetSamplingTime();

private:
    int Ts{0};
    unsigned long offset {0};
};