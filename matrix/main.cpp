#include "iostream"
#include "vector"
#include <vector>
using namespace std;

//matrix from 17

void ex17(int ( &matrix )[3][5], int k){
	int ansMultilpy = 1;
	int ansAdition = 0;
	for (int j = 0; j < 5; j++){
		ansAdition += matrix[k][j];
		ansMultilpy *= matrix[k][j];
	}
	cout << ansAdition << ' ' << ansMultilpy << endl;
};

void ex18(int(&matrix)[3][5], int k){
	int ansMultilpy = 1;
	int ansAdition = 0;
	for (int j = 0; j < 3; j++){
		ansAdition += matrix[j][k];
		ansMultilpy *= matrix[j][k];
	}
	cout << ansAdition << ' ' << ansMultilpy << endl;
};

void ex19(int(&matrix)[3][5]){
	vector<int> ans;
	for (int i = 0; i < 3; i++){
		int a = 1;
		for (int j = 0; j < 5; j++){
			a *= matrix[i][j];
		}
		ans.push_back(a);
	}
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << endl;

}

void ex20(int(&matrix)[3][5]){
	vector<int> ans;
	for (int col = 0; col < 5; col++){
		int a = 1;
		for (int row = 0; row < 3; row++){
			a *= matrix[row][col];
		}
		ans.push_back(a);
	}
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << endl;

}

void ex21(int(&matrix)[3][5]){
	vector<int> ans;
	for (int i = 0; i < 3; i += 2){
		int a = 0;
		for (int j = 0; j < 5; j++){
			a += matrix[i][j];
		}
		ans.push_back(a/5);
	}
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << endl;
}

void ex22(int(&matrix)[3][5]){
	vector<int> ans;
	for (int col = 1; col < 5; col += 2){
		int a = 0;
		for (int row = 0; row < 3; row++){
			a += matrix[row][col];
		}
		ans.push_back(a / 3);
	}
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << endl;
}

void ex23(int(&matrix)[3][5]){
	vector<int> ans;
	for (int i = 0; i < 3; i++){
		int min = matrix[i][0];
		for (int j = 0; j < 5; j++){
			if (matrix[i][j] < min){
				min = matrix[i][j];
			}
		}
		ans.push_back(min);
	}
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << endl;
}

void ex24(int(&matrix)[3][5]){
	vector<int> ans;
	for (int col = 0; col < 5; col++){
		int max = matrix[0][col];
		for (int row = 0; row < 3; row++){
			if (matrix[row][col] > max){
				max = matrix[row][col];
			}
		}
		ans.push_back(max);
	}
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << endl;
}

void ex25(int(&matrix)[3][5]){
	int rowNum = 0;
	int maxSum = -100000;
	for (int i = 0; i < 3; i++){
		int sum = 0;
		for (int j = 0; j < 5; j++){
			sum += matrix[i][j];
		}
		if (sum > maxSum){
			maxSum = sum;
			rowNum = i+1;
		}
	}
	cout << rowNum << " " << maxSum << endl;
}

void ex26(int(&matrix)[3][5]){
	int colNum = 0;
	int maxMultiplies = 1;
	for (int col = 0; col < 5; col++){
		int multiplies = 1;
		for (int row = 0; row < 3; row++){
			multiplies *= matrix[row][col];
		}
		if (multiplies > maxMultiplies){
			maxMultiplies = multiplies;
			colNum = col + 1;
		}
	}
	cout << colNum << " " << maxMultiplies << endl;
}

void ex27(int(&matrix)[3][5]){
    vector<int> minInRow;
    for (int i = 0; i < 3; i++){
    int min = matrix[i][0];
    for (int j = 0; j < 5; j++){
        if (matrix[i][j] < min){
            min = matrix[i][j];
        }
    }
    minInRow.push_back(min);
    }
    int ans = matrix[0][0];
    for (int i = 0; i < minInRow.size(); i++){
        if (minInRow[i] > ans){
            ans = minInRow[i];
        }
    }
    cout << ans << endl;
}

void ex28(int(&matrix)[3][5]){
    vector<int> maxInRow;
    for (int i = 0; i < 5; i++){
    int min = matrix[0][i];
    for (int j = 0; j < 3; j++){
        if (matrix[i][j] < min){
            min = matrix[i][j];
        }
    }
    maxInRow.push_back(min);
    }
    int ans = matrix[0][0];
    for (int i = 0; i < 3; i++){
        if (maxInRow[i] < ans){
            ans = maxInRow[i];
        }
    }
    cout << ans << endl;   
}

void ex29(int(&matrix)[3][5]){
    vector<int> ans;
    for (int i = 0; i < 3; i++){
        int sum = 0;
        int count = 0;
        for (int j = 0; j < 5; j++){
            sum += matrix[i][j];
        }
        for (int k = 0; k < 5; k++){
            if (matrix[i][k] < sum / 5){
                count++;
            }
        }
        ans.push_back(count);
    }
    for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
}
int main() {
	int matrix[3][5] = {
		{ 1, 2, 3, 4, 5 },
		{ 2, 4, 6, 8, 10 },
		{ 3, 6, 9, 12, 15 }
	};
	ex17(matrix, 1);
	ex18(matrix, 1);
	ex19(matrix);
	ex20(matrix);
	ex21(matrix);
	ex22(matrix);
	ex23(matrix);
	ex24(matrix);
	ex25(matrix);
	ex26(matrix);
	ex27(matrix);
	ex28(matrix);
	ex29(matrix);
	return 0;
}