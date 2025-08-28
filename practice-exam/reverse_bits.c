#include <unistd.h>

unsigned char reverse_bits(unsigned char octet)
{
	unsigned char res;
	res= 0;

	if (octet >= 128)
	{
		octet -= 128;
		res += 1;
	}
	if (octet >= 64)
	{
		octet -= 64;
		res += 2;
	}
	if (octet >= 32)
	{
		octet -= 32;
		res += 4;
	}
	if (octet >= 16)
	{
		octet -= 16;
		res += 8
	}
	if (octet >= 8)
	{
		octet -= 8;
		res += 16;
	}
	if (octet >= 4)
	{
		octet -= 4;
		res += 32;
	}
	if (octet >= 2)
	{
		octet -= 2;
		res += 64;
	}
	if (octet >= 1)
	{
		octet -= 1;
		res += 128;
	}
	return (res);
}
