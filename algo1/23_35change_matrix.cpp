#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
	int collum=0;
	int row=0;
	cin>>row;
    cin>>collum;
    //cout<<row<<collum<<endl;
    int matrix[row][collum];
    int matrixo[row][collum];
    for(int j=0;j<row;j++){
        for(int i=0;i<collum;i++){
            cin>>matrix[j][i];
            matrixo[j][i]=matrix[j][i];
        }
    }

    for(int k=0;k<row;k++){
        for(int l=0;l<collum;l++){
            int f=0;
            if(matrix[k][l]==35 || matrix[k][l]==23){
                for(int u=1;u>-2;u--){
                    for(int s=1;s>-2;s--){
                        if(k-u<0||l-s<0){
                            continue;
                        }
                        else if(k-u>=row||l-s>=collum){
                            continue;
                        }
                        if(matrixo[k-u][l-s]==matrix[k][l]){
                            f++;
                        }
                    }
                }
            }
            if(f==1){
                if(matrix[k][l]==35){
                    matrix[k][l]=23;
                }
                else if(matrix[k][l]==23){
                    matrix[k][l]=35;
                }
            }
        }
    }
    for(int o=0;o<row;o++){
        for(int e=0;e<collum;e++){
            cout<<matrix[o][e]<<" ";
        }
        cout<<"\n";
    }




	

	return 0;
}
