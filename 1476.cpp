#include<iostream>
int e,s,m,i=1;
main(){
	for(std::cin>>e>>s>>m; e%15!=i%15||s%28!=i%28||m%19!=i%19; i++);
	std::cout<<i;
}
