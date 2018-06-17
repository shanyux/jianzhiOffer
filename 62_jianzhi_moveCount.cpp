class Solution
{
  public:
    int movingCount(int threshold, int rows, int cols)
    {
        bool *visit = new bool[rows * cols]();
        int count = comCount(threshold, rows, cols, 0, 0, visit);
        delete[] visit;
        return count;
    }
    int comCount(int threshold, int rows, int cols, int i, int j, bool *visit)
    {
        int count = 0;
        if (check(threshold, rows, cols, i, j, visit))
        {
            visit[i * cols + j] = 1;
            count = 1 + comCount(threshold, rows, cols, i + 1, j, visit) +
                    comCount(threshold, rows, cols, i, j + 1, visit) +
                    comCount(threshold, rows, cols, i - 1, j, visit) +
                    comCount(threshold, rows, cols, i, j - 1, visit);
        }
        return count;
    }
    bool check(int threshold, int rows, int cols, int i, int j, bool *visit)
    {
        if (i >= 0 && i < rows && j >= 0 && j < cols && !visit[i * cols + j] && getvalue(i) + getvalue(j) <= threshold)
        {
            return true;
        }
        return false;
    }
    int getvalue(int v)
    {
        int value = 0;
        while (v > 0)
        {
            value += v % 10;
            v /= 10;
        }
        return value;
    }
};