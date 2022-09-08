#define _CRT_SECURE_NO_WARNINGS 1 

int GetNumberOfK(int* data, int dataLen, int k) {
    // write code here
    int count = 0;
    int x = 0;
    for (int i = 0; i < dataLen; i++)
    {
        x = data[i] ^ k;
        if (x == 0)
        {
            count++;
        }
    }
    return count;
}

int convertInteger(int A, int B) {
    int c = A ^ B;
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        if ((c >> i) & 1)
        {
            count++;
        }
    }
    return count;
}