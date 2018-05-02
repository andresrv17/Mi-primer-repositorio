#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void showm(vector<vector<int> > ma, int m, int n){
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			cout<<"  "<<ma[i][j]<<" ";
		}
		cout<<endl;
	}
}
void showv(vector<int> v, int n){
	for(int i=0;i<n;i++){
			cout<<" "<<v[i]<<" ";
		}
		cout<<endl;
}
void bankero(vector<vector<int> >ma,vector<vector<int> >ms,vector<int>vd,vector<int>ve,vector<int>sum,int m,int n){
	int p,it=0;
	while(vd!=ve){
	vector<int> menmay(m);
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			if((ms[i][j]<=vd[i])&&ms[i][j]>=0){
				menmay[j]+=1;
			}
		}
		if(menmay[j]==4){
			p=j;
			break;
		}
		else{
			if(j==m&&menmay[j]<4){
				cout<<"Estado inseguro"<<endl;
				cout<<endl<<"Vector de disponibles: "<<endl;
				showv(vd,n);
				cout<<endl<<"Matriz de necesidades: "<<endl;
				showm(ms,m,n);
				return;
			}
		}
	}
	for(int i=0;i<n;i++){
		ma[i][p]+=ms[i][p];
		vd[i]-=ms[i][p];
		sum[i]+=ms[i][p];
		ms[i][p]=0;
	}
	cout<<endl<<"Vector de existentes: "<<endl;
	showv(ve,n);
	cout<<endl<<"Vector de disponibles: "<<endl;
	showv(vd,n);
	cout<<endl<<"Matriz de necesidades: "<<endl;
	showm(ms,m,n);
	cout<<endl<<"Matriz de asignaciones: "<<endl;
	showm(ma,m,n);
	it++;
	cout<<"----------------------------------------------"<<it<<endl;

	for(int i=0;i<n;i++){
		vd[i]+=ma[i][p];
		sum[i]-=ma[i][p];
		ma[i][p]=-1;
		ms[i][p]=-1;
	}
	cout<<endl<<"Vector de existentes: "<<endl;
	showv(ve,n);
	cout<<endl<<"Vector de disponibles: "<<endl;
	showv(vd,n);
	cout<<endl<<"Matriz de necesidades: "<<endl;
	showm(ms,m,n);
	cout<<endl<<"Matriz de asignaciones: "<<endl;
	showm(ma,m,n);
	it++;
	cout<<"----------------------------------------------"<<it<<endl;}
}
int main(){
	int m,n;
	cout<<"Ingrese la cantidad de procesos: ";
	cin>>m;
	cout<<"Ingrese el número de recursos: ";
	cin>>n;
	cout<<"Ingrese el vector de Existentes(digito a digito)."<<endl;
	vector<int> ve(n);//Vector de existentes
	vector<int> sum(n,0);//vector que va llevando la suma de asignados por recurso
	int andres=1000;
	int holi="este es un string"
	for(int i=0;i<n;i++){
		cin>>ve[i];//ingreso vector de existentes
	}
	vector<vector<int> > ms(n),ma(n);
	for(int i = 0; i<n; i++){//les doy tamano a los vectores que comonen la matriz
		ms[i].resize(m);
		ma[i].resize(m);
	}
	cout<<"Ingrese la matriz de los que se necesitan: "<<endl;
	for(int j=0; j<m; j++){
		for(int i=0; i<n; i++){
			for(;;){
				cin>>ms[i][j];
				if(ms[i][j]>ve[i]){
					cout<<"Es mayor a los existentes, ingrese de nuevo."<<endl;
					showm(ms,m,n);
				}
				else{
					break;
				}
			
			}
		} 
	}
	cout<<"Ingrese matriz de asignaciones: "<<endl;
	for(int j=0; j<m; j++){
		for(int i=0; i<n; i++){
			for(;;){
				cin>>ma[i][j];
				if(ma[i][j]>ve[i]){
					cout<<"Es mayor a los existentes o a los solicitados, verifique y reasigne."<<endl;
					showm(ma,m,n);
				}
				else{
					sum[i]+=ma[i][j];
					if(sum[i]>ve[i]){
						cout<<"La asignacion mayor a los existentes, ingrese de nuevo."<<endl;
						sum[i]-=ma[i][j];
						showm(ma,m,n);
					}
					else{
						break;
					}
				}	
			}
		} 
	}
	vector<int> vd(n);
	for(int i=0;i<n;i++){
		vd[i]=ve[i]-sum[i];
	}
	cout<<endl<<"Vector de existentes: "<<endl;
	showv(ve,n);
	cout<<endl<<"Vector de disponibles: "<<endl;
	showv(vd,n);
	cout<<endl<<"Matriz de necesidades: "<<endl;
	showm(ms,m,n);
	cout<<endl<<"Matriz de asignaciones: "<<endl;
	showm(ma,m,n);
	
	bankero(ma,ms,vd,ve,sum,m,n);

}
