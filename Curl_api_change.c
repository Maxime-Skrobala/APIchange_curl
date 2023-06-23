#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include </home/user/curl-8.1.1/include/curl/curl.h>

struct couple
{
    float from;
    float to ;
};

struct couple_s{
    char* str_from;
    char* str_to;
};

typedef struct couple couple;
typedef struct couple_s couple_s;

char* access_key = "******************************";

size_t get_data(char* buffer,size_t itemsize,size_t nitem,void* nn){
    size_t n = itemsize * nitem;
    FILE* fichier = fopen("/home/user/data.txt","w+");

    for (int i = 0; i < n; i++)
    {
        fprintf(fichier,"%c",buffer[i]);
    }

    fclose(fichier);


    return n;
}

char* remove_last(char* c){
    int n = strlen(c);
    char* s = malloc(sizeof(char)*(n));
    for (int i = 0; i < n-1; i++)
    {
        s[i]=c[i];
    }
    
    
    s[n-1]='\0';
    return s;
}

couple_s get_change(char* from,char* to){
    couple_s res;
    FILE* fichier = fopen("/home/user/data.txt","r");
    char* line = malloc(sizeof(char)*500);
    res.str_from = malloc(sizeof(char)*100);
    res.str_to = malloc(sizeof(char)*100);
    while (fscanf(fichier,"%s",line) != EOF){
        int i = 0;
        int n = strlen(line);
        while(i<(n-3)){
            if (line[i]==from[0] && line[i+1]==from[1] && line[i+2]==from[2]){
                strcpy( res.str_from, remove_last(&line[6]));
            }
            if (line[i]==to[0] && line[i+1]==to[1] && line[i+2]==to[2]){
                strcpy( res.str_to, remove_last(&line[6]));      
            }
            i++;   
        }
    }
    return res;
}

float taux (float from, float to){
    return to/from;

}

void reset(char* filename){
    FILE* fichier = fopen("/home/user/data.txt","w");
}

int main(){
    CURL* curl = curl_easy_init();
    curl_easy_setopt(curl,CURLOPT_URL,"http://data.fixer.io/api/latest?access_key=************************&format=1&_gl=1*1657z8o*_ga*MTcwOTAxNjU5Ny4xNjg1MzExMzMx*_ga_HGV43FGGVM*MTY4NTMxMTMzMC4xLjEuMTY4NTMxNDY2Mi41OC4wLjA.");
    curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,get_data);
    curl_easy_perform(curl);

    printf("%s","_____________________________________________________________________________________\n");
    printf("%s","|AED|AFN|ALL|AMD|ANG|AOA|ARS|AUD|AWG|AZN|BAM|BBD|BDT|BGN|BHD|BIF|BMD|BND|BOB|BRL|BSD|\n");
    printf("%s","|BTC|BTN|BWP|BYN|BYR|BZD|CAD|CDF|CHF|CLF|CLP|CNY|COP|CRC|CUC|CUP|CVE|CZK|DJF|DKK|DOP|\n");
    printf("%s","|DZD|EGP|ERN|ETB|EUR|FJD|FKP|GBP|GEL|GGP|GHS|GIP|GMD|GNF|GTQ|GYD|HKD|HNL|HRK|HTG|HUF|\n");
    printf("%s","|IDR|ILS|IMP|INR|IQD|IRR|ISK|JEP|JMD|JOD|JPY|KES|KGS|KHR|KMF|KPW|KRW|KWD|KYD|KZT|LAK|\n");
    printf("%s","|LBP|LKR|LRD|LSL|LTL|LVL|LYD|MAD|MDL|MGA|MKD|MMK|MNT|MOP|MRO|MUR|MVR|MWK|MXN|MYR|MZN|\n");
    printf("%s","|NAD|NGN|NIO|NOK|NPR|NZD|OMR|PAB|PEN|PGK|PHP|PKR|PLN|PYG|QAR|RON|RSD|RUB|RWF|SAR|SBD|\n");
    printf("%s","|SCR|SDG|SEK|SGD|SHP|SLE|SLL|SOS|SRD|STD|SVC|SYP|SZL|THB|TJS|TMT|TND|TOP|TRY|TTD|TWD|\n");
    printf("%s","|TZS|UAH|UGX|USD|UYU|UZS|VEF|VES|VND|VUV|WST|XAF|XAG|XAU|XCD|XDR|XOF|XPF|YER|ZAR|ZMK|\n");
    printf("%s","|ZMW|ZWL|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |\n");
    printf("%s","‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
    printf("%s","\n");
    printf("%s","\n");
    printf("%s","\n");

    char* in_from=malloc(sizeof(char)*4);
    char* in_to=malloc(sizeof(char)*4);
    printf("%s","Monaie d'origine : ");
    scanf("%s",in_from);
    printf("%s","Monaie d'arrivée : ");
    scanf("%s",in_to);
    printf("%s","\n");
    printf("%s","\n");
    printf("%s","\n");
    
    
    couple_s data_s = get_change(in_from,in_to);
    couple data;
    data.from=atof(data_s.str_from);
    data.to=atof(data_s.str_to);
    printf("%s%f","Prix monaie d'origine : ",data.from);
    printf("%s","\n");
    printf("%s%f","Prix monaie d'arrivée : ",data.to);

    printf("%s","\n");
    printf("%s","\n");
    printf("%s","\n");
    printf("%s","\n");

    printf("%s%f","Taux de change: ",taux(data.from,data.to));
    printf("%s","\n");

    float quant;
    printf("%s","Quantintée à convertir : ");
    scanf("%f",&quant);
    printf("%s","\n");
    printf("%s","\n");
    printf("%s","\n");
    printf("%s%f","Quantintée reçue : ",taux(data.from,data.to)*quant);
    printf("%s","\n");

    
    reset("/home/user/data.txt");


    curl_easy_cleanup(curl);
    return 0;
}