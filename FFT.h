#pragma once

typedef struct complex //��������  
{
	float Re;       //ʵ��  
	float Im;       //�鲿  
}complex;

#define PI 3.1415926535897932384626433832795028841971  


///////////////////////////////////////////  
void conjugate_complex(int n, complex in[], complex out[]);
void c_plus(complex a, complex b, complex *c);//������  
void c_mul(complex a, complex b, complex *c);//������  
void c_sub(complex a, complex b, complex *c); //��������  
void c_div(complex a, complex b, complex *c); //��������  
void FFT(int N, complex f[]);//����Ҷ�任 ���Ҳ��������f��  
void IFFT(int N, complex f[]); // ����Ҷ��任  
void c_abs(complex f[], float out[], int n);//��������ȡģ 
void DFT(complex *data, complex *X, int K);
////////////////////////////////////////////