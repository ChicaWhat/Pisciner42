#include <unistd.h>                                                             
#include <stdio.h>                                                              
                                                                                
int ft_atoi(char *str)                                                             
{                                                                               
        int i = 0;                                                              
        int sign = 1;                                                           
        int num = 0;                                                               
        while (str[i] <= 32)                                                    
                i++;                                                            
        while (str[i] == '-' || str[i] == '+')                                  
        {                                                                       
            if (str[i] == '-')                                                  
                sign *= -1;                                                     
            i++;
        }                                        
        while (str[i] >= '0' && str[i] <= '9')
		{
                num = (num * 10) + str[i] - '0';
				i++;
		}                                                      
        return (num * sign);                                                           
}

int main(void)
{
		char str[3] = "123";
		printf("Numero: %d\n", ft_atoi(str));
		return (0);
}
