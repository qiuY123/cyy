#define _CRT_SECURE_NO_WARNINGS 1 

#define EVEN_BIT 0x55555555
#define ODD_BIT 0xAAAAAAAA

int exchangeBits(int num) 
{
	return ((EVEN_BIT & num) << 1) | ((ODD_BIT & num) >> 1);
}

char* compressString(char* S) 
{
    int size = strlen(S);
    if (size <= 2) 
        return S;
    char* temp = (char*)malloc(sizeof(char) * (2 * size));
    temp[0] = S[0];
    int count = 1, index = 1;
    for (int i = 1; i < size + 1; i++) 
    {
        if (S[i] == S[i - 1]) 
        {
            count++;
        }
        else 
        {
            int num = (int)log10(count) + index;
            index = num;
            while (count) 
            {
                temp[num--] = count % 10 + '0';
                count /= 10;
            }
            temp[++index] = S[i];
            count = 1;
            ++index;
        }
    }
    if (index >= size + 1) 
        return S;
    return temp;
}
