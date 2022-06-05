//ARITHMETIC OPERATIONS ON COMPLEX NUMBERS

#include<stdio.h>

struct complex
{
	float real;
	float comp;
};

struct complex add(struct complex a1,struct complex a2)
{
	struct complex s;
	s.real=a1.real+a2.real;
	s.comp=a1.comp+a2.comp;
	return s;
}

struct complex subtract(struct complex a1,struct complex a2)
{
	struct complex d;
	d.real=a1.real-a2.real;
	d.comp=a1.comp-a2.comp;
	return d;
}

struct complex product(struct complex a1,struct complex a2)
{
	struct complex p;
	p.real=((a1.real*a2.real)-(a1.comp*a2.comp));
	p.comp=((a1.real*a2.comp)+(a1.comp*a2.real));
	return p;
}

struct complex division(struct complex a1,struct complex a2)
{
	struct complex d,conjugate;
	conjugate.real=a2.real;
	conjugate.comp=a2.comp*(-1);
	d=product(a1,conjugate);
	d.real/=((a2.real*a2.real) + (a2.comp*a2.comp));
	d.comp/=((a2.real*a2.real) + (a2.comp*a2.comp));
	return d;
}

int main()
{
	struct complex c1,c2,c3;
	printf("\nEnter the real part of the 1st complex number : ");
	scanf("%f",&c1.real);
	printf("\nEnter the complex part of the 1st complex number : ");
	scanf("%f",&c1.comp);
	printf("\nEnter the real part of the 2nd complex number : ");
	scanf("%f",&c2.real);
	printf("\nEnter the complex part of the 2nd complex number : ");
	scanf("%f",&c2.comp);
	c3=add(c1,c2);
	printf("\nSum = %f + %f i",c3.real,c3.comp);
	c3=subtract(c1,c2);
	printf("\nDifference = %f + %f i",c3.real,c3.comp);
	c3=product(c1,c2);
	printf("\nProduct = %f + %f i",c3.real,c3.comp);
	if((c2.real==0.0) && (c2.real==0.0))
	{
		printf("\nDivision not possible...");
	}
	else
	{
		c3=division(c1,c2);
		printf("\nDivision = %f + %f i",c3.real,c3.comp);
		printf("\n");
	}
	return 0;
}