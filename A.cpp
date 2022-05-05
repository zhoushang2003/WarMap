#import<bits/stdc++.h>
using namespace std;
const int N=26,X=100,Y=100,R=10,U[]={-1,0,0,1},V[]={0,-1,1,0},S[]={12546,9824,6020,2888,1084,318,73,13,2};
int c[999][999],s[99],g[99][99],C,x,y,P[99],Q[99],t,p,q,f[99],G[99],h[99],u;
double a[99],b[99],l;
double D(double x,double y,double z,double w)
{
	return sqrt((x-z)*(x-z)+(y-w)*(y-w));
}
int O()
{
	x=rand(),y=0;
	while(x>=0)
		x-=S[y++];
	return y*100;
}
main()
{
	srand(time(0));
	for(int i=1;i<=N;i++)
		a[i]=rand()%X+1,b[i]=rand()%Y+1;
	for(int i=1;i<=R;i++)
	{
		for(int j=1;j<=X;j++)
			for(int k=1;k<=Y;k++)
				for(int l=1;l<=N;l++)
					if(D(a[l],b[l],j,k)<D(a[c[j][k]],b[c[j][k]],j,k))
						c[j][k]=l;
		for(int j=1;j<=N;j++)
			a[j]=b[j]=s[j]=0;
		for(int j=1;j<=X;j++)
			for(int k=1;k<=Y;k++)
				s[c[j][k]]++;
		for(int j=1;j<=X;j++)
			for(int k=1;k<=Y;k++)
				a[c[j][k]]+=1.0*j/s[c[j][k]],b[c[j][k]]+=1.0*k/s[c[j][k]];
	}
	memset(g,0x3f3f,sizeof(g));
	for(int i=1;i<=X;i++)
		for(int j=1;j<=Y;j++)
			for(int k=0;k<4;k++)
				g[c[i][j]][c[i+U[k]][j+V[k]]]=1;
	for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for(int i=1;i<=N;i++)
		f[i]=O(),G[i]=5*f[i];
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			x=max(x,g[i][j]);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			if(g[i][j]==x)
				P[++t]=i,Q[t]=j;
	x=rand()%t+1,p=P[x],q=Q[x],f[p]=f[q]=1000,G[p]=0,G[q]=500,h[p]=-1,h[q]=1;
	for(int i=1;i<=N;i++)
		a[i]=(a[i]-1)/99*600-32.5,b[i]=(b[i]-1)/99*600-32.5;
	freopen("index.html","w",stdout);
	cout<<"<!DOCTYPE html>\n";
	cout<<"<html lang="<<'"'<<"en"<<'"'<<"dir="<<'"'<<"ltr"<<'"'<<">\n";
	cout<<"<head>\n";
	cout<<"\t<meta charset="<<'"'<<"utf-8"<<'"'<<">\n";
	cout<<"\t<title>WarMap</title>\n";
	cout<<"\t<link rel="<<'"'<<"stylesheet"<<'"'<<" href="<<'"'<<"styles.css"<<'"'<<">\n";
	cout<<"\t<link href="<<'"'<<"https://fonts.googleapis.com/css?family=Arvo"<<'"'<<" rel="<<'"'<<"stylesheet"<<'"'<<">\n";
	cout<<"\t<link rel="<<'"'<<"icon"<<'"'<<" href="<<'"'<<"favicon.ico"<<'"'<<">\n";
	cout<<"</head>\n";
	cout<<"<body>\n";
	cout<<"\t<div id="<<'"'<<"container"<<'"'<<">\n";
	for(int i=1;i<=N;i++)
		for(int j=i+1;j<=N;j++)
			if(g[i][j]==1)
				u++;
	for(int i=1;i<=u;i++)
		cout<<"\t\t<hr id="<<'"'<<"l"<<i<<'"'<<">\n";
    for(int i=1;i<=N;i++)
    	cout<<"\t\t<button id="<<'"'<<(char)(i-1+'a')<<'"'<<" class="<<'"'<<"t"<<'"'<<"></button>\n";
	cout<<"\t</div>\n";
	cout<<"<script src="<<'"'<<"index.js"<<'"'<<" charset="<<'"'<<"utf-8"<<'"'<<"></script>\n";
	cout<<"</body>\n";
	cout<<"</html>\n";
	freopen("styles.css","w",stdout);
	cout<<"body\n";
	cout<<"{\n";
	cout<<"\ttext-align:center;\n";
	cout<<"\tbackground-color:#524C84;\n";
	cout<<"}\n";
	cout<<"hr\n";
	cout<<"{\n";
	cout<<"\tbackground-color:black;\n";
	cout<<"\theight:3px;\n";
	cout<<"\tmargin:0px;\n";
	cout<<"\tborder:0px;\n";
	cout<<"\tposition:absolute;\n";
	cout<<"}\n";
	cout<<".t\n";
	cout<<"{\n";
	cout<<"\tborder:10px solid #404B69;\n";
	cout<<"\tfont-size:0.65rem;\n";
	cout<<"\tfont-family:'Arvo',cursive;\n";
	cout<<"\tfont-weight:900;\n";
	cout<<"\tline-height:2;\n";
	cout<<"\tcolor:#494953;\n";
	cout<<"\tborder-radius:15px;\n";
	cout<<"\twidth:65px;\n";
	cout<<"\theight:65px;\n";
	cout<<"\tmargin:0px;\n";
	cout<<"\tposition:absolute;\n";
	cout<<"}\n";
	cout<<".pressed\n";
	cout<<"{\n";
	cout<<"\tbox-shadow:0 3px 4px 0 #DBEDF3;\n";
	cout<<"\topacity:0.5;\n";
	cout<<"}\n";
	cout<<"#container\n";
	cout<<"{\n";
	cout<<"\tposition:absolute;\n";
	cout<<"\twidth:600px;\n";
	cout<<"\theight:600px;\n";
	cout<<"\tleft:468px;\n";
	cout<<"\ttop:76.8px;\n";
	cout<<"}\n";
	for(int i=1;i<=N;i++)
		for(int j=i+1;j<=N;j++)
			if(g[i][j]==1)
				cout<<"#l"<<++C<<"\n{\n\twidth:"<<D(a[i],b[i],a[j],b[j])<<"px;\n\tleft:"<<(a[i]+a[j]-D(a[i],b[i],a[j],b[j])+65)/2<<"px;\n\ttop:"<<(b[i]+b[j]+65)/2<<"px;\n\t-webkit-transform:rotate("<<atan((b[i]-b[j])/(a[i]-a[j]))-acos(-1)<<"rad);\n}\n";
	for(int i=1;i<=N;i++)
		cout<<'#'<<(char)(i-1+'a')<<'\n'<<"{\n\tleft:"<<a[i]<<"px;\n\ttop:"<<b[i]<<"px;\n}\n";
	freopen("index.js","w",stdout);
	cout<<"var f=[";
	for(int i=1;i<N;i++)
		cout<<f[i]<<',';
	cout<<f[N]<<"];\nvar g=[";
	for(int i=1;i<N;i++)
		cout<<G[i]<<',';
	cout<<G[N]<<"];\nvar h=[";
	for(int i=1;i<N;i++)
		cout<<h[i]<<',';
	cout<<h[N]<<"];\n";
	cout<<"var l=[";
	for(int i=1;i<=N;i++)
	{
		cout<<'[';
		for(int j=1;j<N;j++)
			cout<<g[i][j]<<",";
		cout<<g[i][N]<<']';
		if(i<N)
			cout<<',';
	}
	cout<<"];\n";
	cout<<"var p="<<p-1<<";\n";
	cout<<"var q="<<q-1<<";\n";
	cout<<"var x=0;\n";
	cout<<"var y=0;\n";
	cout<<"var c=0;\n";
	cout<<"function A()\n";
	cout<<"{\n";
	cout<<"\tfor(var i=0;i<26;i++)\n";
	cout<<"\t\tif(h[i]==-1)\n";
	cout<<"\t\t\tg[i]+=f[i];\n";
	cout<<"}\n";
	cout<<"function B()\n";
	cout<<"{\n";
	cout<<"\tfor(var i=0;i<26;i++)\n";
	cout<<"\t\tif(h[i]==1)\n";
	cout<<"\t\t\tg[i]+=f[i];\n";
	cout<<"}\n";
	cout<<"function O()\n";
	cout<<"{\n";
	cout<<"\tif(h[p]==1)\n";
	cout<<"\t\tfor(var i=0;i<26;i++)\n";
	cout<<"\t\t\tif(h[i]==-1)\n";
	cout<<"\t\t\t\th[i]=1;\n";
	cout<<"\tif(h[q]==-1)\n";
	cout<<"\t\tfor(var i=0;i<26;i++)\n";
	cout<<"\t\t\tif(h[i]==1)\n";
	cout<<"\t\t\t\t\th[i]=-1;\n";
	cout<<"\tfor(var i=0;i<26;i++)\n";
	cout<<"\t{\n";
	cout<<"\t\tdocument.querySelectorAll("<<'"'<<".t"<<'"'<<")[i].innerHTML=f[i]+"<<'"'<<(char)92<<'n'<<'"'<<"+g[i];\n";
	cout<<"\t\tif(h[i]==0)\n";
	cout<<"\t\t\tdocument.querySelectorAll("<<'"'<<".t"<<'"'<<")[i].style.backgroundColor="<<'"'<<"#EEEEEE"<<'"'<<";\n";
	cout<<"\t\telse if(h[i]==-1)\n";
	cout<<"\t\t\tdocument.querySelectorAll("<<'"'<<".t"<<'"'<<")[i].style.backgroundColor="<<'"'<<"#D65D7A"<<'"'<<";\n";
	cout<<"\t\telse\n";
	cout<<"\t\t\tdocument.querySelectorAll("<<'"'<<".t"<<'"'<<")[i].style.backgroundColor="<<'"'<<"#92E6E6"<<'"'<<";\n";
	cout<<"\t}\n";
	cout<<"}\n";
	cout<<"function T(k)\n";
	cout<<"{\n";
	cout<<"var t=document.querySelectorAll("<<'"'<<".t"<<'"'<<")[k];\n";
	cout<<"t.classList.add("<<'"'<<"pressed"<<'"'<<");\n";
	cout<<"setTimeout(function()\n";
	cout<<"{\n";
	cout<<"\tt.classList.remove("<<'"'<<"pressed"<<'"'<<");\n";
	cout<<"},100);\n";
	cout<<"}\n";
	cout<<"A();\n";
	cout<<"O();\n";
	cout<<"for(var i=0;i<26;i++)\n";
	cout<<"\tdocument.querySelectorAll("<<'"'<<".t"<<'"'<<")[i].addEventListener("<<'"'<<"click"<<'"'<<",function()\n";
	cout<<"\t{\n";
	cout<<"\t\tc++;\n";
	cout<<"\t\ty=this.id.charCodeAt(0)-97;\n";
	cout<<"\t\tif(c%4==1)\n";
	cout<<"\t\t{\n";
	cout<<"\t\t\tif(h[y]==-1)\n";
	cout<<"\t\t\t{\n";
	cout<<"\t\t\t\tx=y;\n";
	cout<<"\t\t\t\tT(y);\n";
	cout<<"\t\t\t}\n";
	cout<<"\t\t\telse\n";
	cout<<"\t\t\t\tc--;\n";
	cout<<"\t\t}\n";
	cout<<"\t\telse if(c%4==2)\n";
	cout<<"\t\t{\n";
	cout<<"\t\t\tif(l[x][y]==1)\n";
	cout<<"\t\t\t{\n";
	cout<<"\t\t\t\tif(x!=y)\n";
	cout<<"\t\t\t\t{\n";
	cout<<"\t\t\t\t\tif(h[x]==h[y])\n";
	cout<<"\t\t\t\t\t\tg[y]+=g[x];\n";
	cout<<"\t\t\t\t\telse if(g[x]>g[y])\n";
	cout<<"\t\t\t\t\t{\n";
	cout<<"\t\t\t\t\t\tg[y]=Math.round(Math.sqrt(g[x]*g[x]-g[y]*g[y]));\n";
	cout<<"\t\t\t\t\t\th[y]=-1;\n";
	cout<<"\t\t\t\t\t}\n";
	cout<<"\t\t\t\t\telse\n";
	cout<<"\t\t\t\t\t\tg[y]=Math.round(Math.sqrt(g[y]*g[y]-g[x]*g[x]));\n";
	cout<<"\t\t\t\t\tg[x]=0;\n";
	cout<<"\t\t\t\t}\n";
	cout<<"\t\t\t\tT(y);\n";
	cout<<"\t\t\t\tB();\n";
	cout<<"\t\t\t}\n";
	cout<<"\t\t\telse\n";
	cout<<"\t\t\t\tc--;\n";
	cout<<"\t\t}\n";
	cout<<"\t\telse if(c%4==3)\n";
	cout<<"\t\t{\n";
	cout<<"\t\t\tif(h[y]==1)\n";
	cout<<"\t\t\t{\n";
	cout<<"\t\t\t\tx=y;\n";
	cout<<"\t\t\t\tT(y);\n";
	cout<<"\t\t\t}\n";
	cout<<"\t\t\telse\n";
	cout<<"\t\t\t\tc--;\n";
	cout<<"\t\t}\n";
	cout<<"\t\telse\n";
	cout<<"\t\t{\n";
	cout<<"\t\t\tif(l[x][y]==1)\n";
	cout<<"\t\t\t{\n";
	cout<<"\t\t\t\tif(x!=y)\n";
	cout<<"\t\t\t\t{\n";
	cout<<"\t\t\t\t\tif(h[x]==h[y])\n";
	cout<<"\t\t\t\t\t\tg[y]+=g[x];\n";
	cout<<"\t\t\t\t\telse if(g[x]>g[y])\n";
	cout<<"\t\t\t\t\t{\n";
	cout<<"\t\t\t\t\t\tg[y]=Math.round(Math.sqrt(g[x]*g[x]-g[y]*g[y]));\n";
	cout<<"\t\t\t\t\t\th[y]=1;\n";
	cout<<"\t\t\t\t\t}\n";
	cout<<"\t\t\t\t\telse\n";
	cout<<"\t\t\t\t\t\tg[y]=Math.round(Math.sqrt(g[y]*g[y]-g[x]*g[x]));\n";
	cout<<"\t\t\t\t\tg[x]=0;\n";
	cout<<"\t\t\t\t}\n";
	cout<<"\t\t\t\tT(y);\n";
	cout<<"\t\t\t\tA();\n";
	cout<<"\t\t\t}\n";
	cout<<"\t\t\telse\n";
	cout<<"\t\t\t\tc--;\n";
	cout<<"\t\t}\n";
	cout<<"\t\tO();\n";
	cout<<"\t});\n";

}
