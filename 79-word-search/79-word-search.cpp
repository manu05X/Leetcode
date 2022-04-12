//Using extra space as visited 2D bool vector to keep track of visited position on board

  class Solution {
  	public:
  		bool search(vector<vector<char>>& board, int i, int j, string& word, int idx, vector<vector<bool>>& visited){
  			// if it is the last char of word, Signifies that we have reached the end of word
  			if(idx == word.length()-1)
  				return true;
  			// else mark visited and call DFS for neighbour in 4 direction
  			visited[i][j] = true;
  			// call DFS for neighbour in 4 direction and increase the index
  			if(i > 0 && !visited[i-1][j] && board[i-1][j] == word[idx+1] && search(board, i-1,j,word,idx+1,visited))
  				return true;

  			if(j > 0 && !visited[i][j-1] && board[i][j-1] == word[idx+1] && search(board, i,j-1,word,idx+1,visited))
  				return true;

  			if(i < board.size()-1 && !visited[i+1][j] && board[i+1][j] == word[idx+1] && search(board, i+1,j,word,idx+1,visited))
  				return true;

  			if(j < board[0].size()-1 && !visited[i][j+1] && board[i][j+1] == word[idx+1] && search(board, i,j+1,word,idx+1,visited))
  				return true;
  			// if backtrack mark it as false
  			visited[i][j] = false;
  			// if none of the case satisfy then return it as false;
  			return false;
  	}

  	bool exist(vector<vector<char>>& board, string word) {
  		int n = board.size();
  		int m = board[0].size();

  		//initilizing visited with false
  		vector<vector<bool>> visited(n, vector<bool>(m,false));

  		for(int i = 0; i < n; i++)
  		{
  			for(int j = 0; j < m; j++)
  			{   //if 0th char  matches then search for rest of char against that index in dfs search
  				if(board[i][j] == word[0] && search(board, i,j,word,0,visited))
  					return true;
  			}
  		}
  		return false;
  	}
 };


/*<-------------------------------------------------Optimizing by get rid of visited vector-------------------------------------------------------------------------------->*/

//Optimizing by get rid of visited vector.

  class Solution {
  	public:
  		bool search(vector<vector<char>>& board, int i, int j, string& word, int idx){
  			// if it is the last char of word ,Signifies that we have reached the end of word
  			if(idx == word.length()-1)
  				return true;
  			// else mark visited and call DFS for neighbour in 4 direction
  			board[i][j] -= 65;
  			// call DFS for neighbour in 4 direction and increase the index
  			if(i > 0 && board[i-1][j] == word[idx+1] && search(board, i-1,j,word,idx+1))
  				return true;

  			if(j > 0  && board[i][j-1] == word[idx+1] && search(board, i,j-1,word,idx+1))
  				return true;

  			if(i < board.size()-1 && board[i+1][j] == word[idx+1] && search(board, i+1,j,word,idx+1))
  				return true;

  			if(j < board[0].size()-1  && board[i][j+1] == word[idx+1] && search(board, i,j+1,word,idx+1))
  				return true;
  			// if backtrack mark it as false
  			board[i][j] += 65;
  			// if none of the case satisfy then return it as false;
  			return false;
  	}

  	bool exist(vector<vector<char>>& board, string word) {
  		int n = board.size();
  		int m = board[0].size();

  		//initilizing visited with false
  		//vector<vector<bool>> visited(n, vector<bool>(m,false));

  		for(int i = 0; i < n; i++)
  		{
  			for(int j = 0; j < m; j++)
  			{   //if 0th char  matches then search for rest of char against that index in dfs search
  				if(board[i][j] == word[0] && search(board, i,j,word,0))
  					return true;
  			}
  		}
  		return false;
  	 }
  	};

/*<----------------------------------------------------------Optimizing the dfs search------------------------------------------------------------------------>*/

class Solution {
  public:

  	bool dfs(vector<vector<char>>&board, int count, int i, int j, string& word)
  	{
  		if(word.size() == count) //Signifies that we have reached the end of search
  			return true;

  		if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[count])
  		return false;
  		//We check if element is within bounds and then check if the character at that is the same as the corresponding character in string word


  		char temp = board[i][j];
  		board[i][j] = ' '; //To show that we have visited this node

  		bool res = dfs(board, count+1, i+1, j, word) || dfs(board, count+1, i-1, j, word) || dfs(board, count+1, i, j+1, word) ||dfs(board, count+1, i, j-1, word); //DFS in all 4 directions

  		board[i][j] = temp; //Restore the element after checking

  		return res;
  	}
  	
  	bool exist(vector<vector<char>>& board, string word)
  	{
  		if(board.empty())
  			return false;

  		for(int i=0; i<board.size(); i++)
  		{
  			for(int j=0; j<board[0].size(); j++)
  			{
  				if(dfs(board, 0, i, j, word))
  					return true;
  			}
  		}

  		return false;
  	}
  };



