#include<iostream>
main() {
	int N1, N2, cases = 0;
	int i, j;
	while(std::cin >> N1 >> N2) {
		if(N1 == 0 && N2 == 0) break;

		int tab[N1], tab2[N2];


		for(i = 1; i <= N1; i++)
			std::cin >> tab[i];
		for(i = 1; i <= N2; i++)
			std::cin >> tab2[i];

		int out[N1 + 1][N2 + 1] = {};

		for(i = 1; i <= N1; i++)
			for(j = 1; j <=N2; j++)
				if(tab[i] == tab2[j]){
					out[i][j] = out[i-1][j-1] + 1;
				}else{
				    if(out[i-1][j] > out[i][j-1])
                        out[i][j] = out[i-1][j];
					else
                        out[i][j] = out[i][j-1];
				}

        std::cout << "Twin Towers #" << ++cases;
        std::cout << "\nNumber of Tiles : " << out[N1][N2] << "\n\n";

        /*for(i = 0; i <= N1; i++){
            for(j = 0; j <= N2; j++){
                std::cout << out[i][j];
                if(j == N2) std::cout << "\n";
            }
        } */

	}
	return 0;
}
