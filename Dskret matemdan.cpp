#include<bits/stdc++.h>
#include<string>
using namespace std;

bool a[1000][1000]={0};
string s;
int b[100]={0};
int ig;

bool  dk(int id,int jd)
 { int jd1,im;
         bool w;
		  
 	if(s[id]=='(') 
 	   { 
 	 	for(im=id+1;im<s.size();im++) 
		if(b[id]==b[im]){ jd1=im; break; }
 	 	if(jd1==jd)  w= dk(id+1,jd-1);	  
		if(s[jd1+1]=='&'&&jd1<s.size()-2) w= dk(id+1,jd1-1) and dk(jd1+2,jd);
		if(s[jd1+1]=='|'&&jd1<s.size()-2) w= dk(id+1,jd1-1) or dk(jd1+2,jd);   
	    if(s[jd1+1]=='p'&&jd1<s.size()-2) w=not(dk(id+1,jd1-1)) or dk(jd1+2,jd);
	    if(s[jd1+1]=='q'&&jd1<s.size()-2) w=(not(dk(id+1,jd1-1) )or dk(jd1+2,jd))and(not(dk(jd1+2,jd)) or dk(id+1,jd1-1));
	   }
	if(s[id]=='!') 
	{   
		 if(s[id+1]=='(') 
 	   { id++; 
 	 	for(im=id+1;im<s.size();im++) 
		if(b[id]==b[im]){ jd1=im; break; }
 	 	if(jd1==jd)  w= dk(id+1,jd-1);	  
		if(s[jd1+1]=='&'&&jd1<s.size()-2) w= dk(id+1,jd1-1) and dk(jd1+2,jd);
		if(s[jd1+1]=='|'&&jd1<s.size()-2) w= dk(id+1,jd1-1) or dk(jd1+2,jd);   
	    if(s[jd1+1]=='p'&&jd1<s.size()-2) w=not(dk(id+1,jd1-1)) or dk(jd1+2,jd);
	    if(s[jd1+1]=='q'&&jd1<s.size()-2) w=(not(dk(id+1,jd1-1) )or dk(jd1+2,jd))and(not(dk(jd1+2,jd)) or dk(id+1,jd1-1));
	   }
		 

	else	 w=not(dk(id+1,id+1));
		
	}
	else
	{if(id==jd) w= a[ig][s[id]-65];
     else 
     {
     	if(s[id+1]=='&'&&id<s.size()-2) w= a[ig][s[id]-65] and dk(id+2,jd);
		if(s[id+1]=='|'&&id<s.size()-2) w= a[ig][s[id]-65] or dk(id+2,jd);   
	    if(s[id+1]=='p'&&id<s.size()-2) w=not(a[ig][s[id]-65]) or dk(id+2,jd);
	    if(s[id+1]=='q'&&id<s.size()-2) w=(not(a[ig][s[id]-65] )or dk(id+2,jd))and(not(dk(id+2,jd)) or a[ig][s[id]-65]);
	    
	 }
	 }
	 return w;
 }


int main()
 {
 	int i,j,j1,k,l,n,m,l1,g;
 	cout<<"Formulani kiriting -->> ";
 	cin>>s;
     
 	 
 	
	 l=0;k=1;
	 for(i=0;i<s.size();i++) 
	  {
	   if(s[i]!='&'&&s[i]!='|'&&s[i]!='!'&&s[i]!='q'&&s[i]!='p'&&s[i]!='('&&s[i]!=')') 
	   {	
	     if(a[0][s[i]-65]==0) {a[0][s[i]-65]=1;l++;}
       }
      if(s[i]=='(') { b[i]=k;k++;  }
      
	  if(s[i]==')') { 
	  for(j=0;j<=i-1;j++)
	  { if(b[j]==0) continue;
	    for(j1=i-1;j1>=0;j1--)
	    {
	      if(b[j1]==0) continue;
	      if(j!=j1&&b[j]==b[j1]) goto x1; 
        }
	   b[i]=b[j];
	  x1:;
	  }
	   }}
	  //for(i=0;i<s.size();i++) cout<<b[i];cout<<endl;	   
	 // Berilgan  satrda nechta o`zgaruvchi borligini topish a[][] va qavslarning orinlari topish b[]
 	
     //cout<<l<<endl;
     l1=l;
     for(j=26;j>=0;j--)
        if(a[0][j]==1)
	 {  i=0;
	     l1--;x:g=0;
	    	  while(g<pow(2,l1)) {a[i+g][j]=1;g++;}
	    	  i+=g;g=0;
	    	  while(g<pow(2,l1)) {a[i+g][j]=0;g++;}
              i+=g;
		 	  if(i<pow(2,l)-1) goto x; 	
	 }
     
     //o`zgaruvcilarga kombinatsiyada a[][] ga qiymatlar berish 
       string sd="",sk="";
	    
	   for(ig=0;ig<pow(2,l);ig++) 
	   {
	    
	   a[ig][27]=dk(0,s.size()-1);//Rostlik jadvali tuzadi a[][]
       
    	    if(a[ig][27]==true) 
    	     { sd+='(';
    	     	for(j=26;j>=0;j--) 
    	     	 {
    	     	 	if(a[0][j]==true)
					   {
					     if(a[ig][j]==true)	{sd+=(char)(j+65);sd+='&';}
						 else  { sd+='!';sd+=(char)(j+65);sd+='&'; }
						}
				  }
    	     sd.erase(sd.end()-1,sd.end());
    	     sd+=')';sd+='|';
			 }
			else 
    	     { sk+='(';
    	     	for(j=26;j>=0;j--) 
    	     	 {
    	     	 	if(a[0][j]==true)
					   {
					     if(a[ig][j]==false)	{sk+=(char)(j+65);sk+='|';}
						 else  { sk+='!';sk+=(char)(j+65);sk+='|'; }
						}
				  }
    	     sk.erase(sk.end()-1,sk.end());
    	     sk+=')';sk+='&';
			 } 
	   
	   }
	   sd.erase(sd.end()-1,sd.end());
	   sk.erase(sk.end()-1,sk.end());
	   
	   for(i=0;i<pow(2,l);i++){
     	cout<<endl;
     	for(j=0;j<=27;j++) cout<<a[i][j];
	 } cout<<endl;
	   cout<<endl;
	   cout<<"Bu formulaning MDNFi -->> "<<sd<<endl<<endl;
	   cout<<"Bu formulaning MKNFi -->> "<<sk<<endl<<endl;
	   cout<<"Etiboringiz uchun raxmat"<<endl;
       //MDNF va MKNF ni topish//
    }
