
//19L-1119, 19L-2308

#include<iostream>
#include <vector>
#include <string>
#include<queue>
#include<stack>
#include<Windows.h>
using namespace std;

class Cube
{
	char front[3][3];
	char back[3][3];
	char up[3][3];
	char down[3][3];
	char right[3][3];
	char left[3][3];

public:
	Cube() {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				front[i][j] = ' ';
				left[i][j] = ' ';
				down[i][j] = ' ';
				right[i][j] = ' ';
				up[i][j] = ' ';
				back[i][j] = ' ';
			}
		}
	}
	Cube(char** front, char** up, char** down, char** left, char** right, char** back)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				this->front[i][j] = front[i][j];
				this->back[i][j] = back[i][j];
				this->up[i][j] = up[i][j];
				this->down[i][j] = down[i][j];
				this->right[i][j] = right[i][j];
				this->left[i][j] = left[i][j];
			}
		}
	}

	//getters
	char** getFront()
	{
		char** f = new char* [3];
		for (int i = 0; i < 3; i++)
		{
			f[i] = new char[3];
			for (int j = 0; j < 3; j++)
			{
				f[i][j] = front[i][j];
			}

		}
		return f;
	}
	char** getRight()
	{
		char** f = new char* [3];
		for (int i = 0; i < 3; i++)
		{
			f[i] = new char[3];
			for (int j = 0; j < 3; j++)
			{
				f[i][j] = right[i][j];
			}

		}
		return f;
	}
	char** getLeft()
	{
		char** f = new char* [3];
		for (int i = 0; i < 3; i++)
		{
			f[i] = new char[3];
			for (int j = 0; j < 3; j++)
			{
				f[i][j] = left[i][j];
			}

		}
		return f;
	}
	char** getDown()
	{
		char** f = new char* [3];
		for (int i = 0; i < 3; i++)
		{
			f[i] = new char[3];
			for (int j = 0; j < 3; j++)
			{
				f[i][j] = down[i][j];
			}

		}
		return f;
	}
	char** getUp()
	{
		char** f = new char* [3];
		for (int i = 0; i < 3; i++)
		{
			f[i] = new char[3];
			for (int j = 0; j < 3; j++)
			{
				f[i][j] = up[i][j];
			}

		}
		return f;
	}
	char** getBack()
	{
		char** f = new char* [3];
		for (int i = 0; i < 3; i++)
		{
			f[i] = new char[3];
			for (int j = 0; j < 3; j++)
			{
				f[i][j] = back[i][j];
			}

		}
		return f;
	}
	//main intializor
	void initializeCube(char f[][3], char b[][3], char l[][3], char r[][3], char u[][3], char d[][3])
	{

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				front[i][j] = f[i][j];
				back[i][j] = b[i][j];
				up[i][j] = u[i][j];
				down[i][j] = d[i][j];
				right[i][j] = r[i][j];
				left[i][j] = l[i][j];
			}
		}

	}

	//swapping
	void swap(char& a1, char& a2, char& a3, char& b1, char& b2, char& b3, char& c1, char& c2, char& c3, char& d1, char& d2, char& d3)
	{
		char t1 = b1;
		char t2 = b2;
		char t3 = b3;
		char s1 = c1;
		char s2 = c2;
		char s3 = c3;
		b1 = a1;
		b2 = a2;
		b3 = a3;
		c1 = t1;
		c2 = t2;
		c3 = t3;
		a1 = d1;
		a2 = d2;
		a3 = d3;
		d1 = s1;
		d2 = s2;
		d3 = s3;
	}
	void swapFB(char& a1, char& a2, char& a3, char& b1, char& b2, char& b3, char& c1, char& c2, char& c3, char& d1, char& d2, char& d3)
	{
		char t1 = b3;
		char t2 = b2;
		char t3 = b1;
		char s1 = c1;
		char s2 = c2;
		char s3 = c3;
		b1 = a3;
		b2 = a2;
		b3 = a1;
		c1 = t1;
		c2 = t2;
		c3 = t3;
		a1 = d1;
		a2 = d2;
		a3 = d3;
		d1 = s1;
		d2 = s2;
		d3 = s3;
	}
	void swapLR(char& a1, char& a2, char& a3, char& b1, char& b2, char& b3, char& c1, char& c2, char& c3, char& d1, char& d2, char& d3)
	{
		char t1 = b3;
		char t2 = b2;
		char t3 = b1;
		char s1 = c1;
		char s2 = c2;
		char s3 = c3;
		b1 = a1;
		b2 = a2;
		b3 = a3;
		c1 = t1;
		c2 = t2;
		c3 = t3;
		a1 = d3;
		a2 = d2;
		a3 = d1;
		d1 = s1;
		d2 = s2;
		d3 = s3;
	}

	//clockwise face rotate
	void clockwise(char arr[][3])
	{
		char swap[3][3];
		int k = 2;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				swap[j][k] = arr[i][j];
			}
			k--;
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				arr[i][j] = swap[i][j];
			}
		}
	}
	//anticlockwise face rotation
	void anticlockwise(char arr[][3])
	{
		char swap[3][3];
		int k = 2;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				swap[k][i] = arr[i][j];
				k--;
			}
			k = 2;
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				arr[i][j] = swap[i][j];
			}
		}
	}

	//6 successor functions
	//top right
	void topRotate(Cube* c)
	{
		//swapping the 1st rows
		swap
		(
			c->front[0][0], c->front[0][1], c->front[0][2],
			c->right[0][0], c->right[0][1], c->right[0][2],
			c->back[0][0], c->back[0][1], c->back[0][2],
			c->left[0][0], c->left[0][1], c->left[0][2]
		);
		anticlockwise(up);
	}
	//down right
	void downRotate(Cube* c)
	{
		//swapping the last rows
		swap
		(
			c->front[2][0], c->front[2][1], c->front[2][2],
			c->right[2][0], c->right[2][1], c->right[2][2],
			c->back[2][0], c->back[2][1], c->back[2][2],
			c->left[2][0], c->left[2][1], c->left[2][2]
		);
		clockwise(down);
	}
	//right down
	void rightRotate(Cube* c)
	{
		//front last col
		//down 1st row 
		//back 1st col
		//up last row
		swapLR
		(
			c->front[0][2], c->front[1][2], c->front[2][2],
			c->down[0][0], c->down[0][1], c->down[0][2],
			c->back[0][0], c->back[1][0], c->back[2][0],
			c->up[2][0], c->up[2][1], c->up[2][2]
		);

		anticlockwise(right);
	}
	//left down
	void leftRotate(Cube* c)
	{
		//swapping the 1st col
		//front 1st col
		// up 1st row
		//down last row
		//back last col
		swapLR
		(
			c->front[0][0], c->front[1][0], c->front[2][0],
			c->down[2][0], c->down[2][1], c->down[2][2],
			c->back[0][2], c->back[1][2], c->back[2][2],
			c->up[0][0], c->up[0][1], c->up[0][2]
		);
		clockwise(left);
	}
	//front anticlockwise
	void frontRotate(Cube* c)
	{
		//swapping the 1st cols
		//last col of left
		swapFB
		(
			c->up[0][0], c->up[1][0], c->up[2][0],
			c->left[0][2], c->left[1][2], c->left[2][2],
			c->down[0][0], c->down[1][0], c->down[2][0],
			c->right[0][0], c->right[1][0], c->right[2][0]
		);
		anticlockwise(front);
	}
	//back clockwise
	void backRotate(Cube* c)
	{
		//swapping the last cols
		//last col of left
		swapFB
		(
			c->up[0][2], c->up[1][2], c->up[2][2],
			c->left[0][0], c->left[1][0], c->left[2][0],
			c->down[0][2], c->down[1][2], c->down[2][2],
			c->right[0][2], c->right[1][2], c->right[2][2]
		);
		clockwise(back);
	}
	void printColoredText(char c)
	{
		HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //just once
		if (c == 'G')
		{
			SetConsoleTextAttribute(color, 10);
			cout << " " << c << " ";
		}
		if (c == 'R')
		{
			SetConsoleTextAttribute(color, 12);
			cout << " " << c << " ";
		}
		if (c == 'B')
		{
			SetConsoleTextAttribute(color, 1);
			cout << " " << c << " ";
		}
		if (c == 'O')
		{
			SetConsoleTextAttribute(color, 6);
			cout << " " << c << " ";
		}
		if (c == 'Y')
		{
			SetConsoleTextAttribute(color, 14);
			cout << " " << c << " ";
		}
		if (c == 'W')
		{
			SetConsoleTextAttribute(color, 15);
			cout << " " << c << " ";
		}
	}
	void printCube()
	{
		HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << "    FRONT        BACK         RIGHT        LEFT        UP         DOWN\n";
		for (int i = 0; i < 3; i++)
		{
			cout << " | ";
			for (int j = 0; j < 3; j++)
			{
				printColoredText(front[i][j]);
			}
			SetConsoleTextAttribute(color, 15);
			cout << " | ";
			for (int j = 0; j < 3; j++)
			{
				printColoredText(back[i][j]);
			}
			SetConsoleTextAttribute(color, 15);
			cout << " | ";
			for (int j = 0; j < 3; j++)
			{
				printColoredText(right[i][j]);
			}
			SetConsoleTextAttribute(color, 15);
			cout << " | ";
			for (int j = 0; j < 3; j++)
			{
				printColoredText(left[i][j]);
			}
			SetConsoleTextAttribute(color, 15);
			cout << " | ";
			for (int j = 0; j < 3; j++)
			{
				printColoredText(up[i][j]);
			}
			SetConsoleTextAttribute(color, 15);
			cout << " | ";
			for (int j = 0; j < 3; j++)
			{
				printColoredText(down[i][j]);
			}
			SetConsoleTextAttribute(color, 15);
			cout << " | ";
			cout << "\n";
		}
	}

	bool match(char arr[][3], char goal)
	{
		bool flag = true;
		for (int i = 0; i < 3 && flag; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[i][j] != goal)
				{
					flag = false;
					break;
				}
			}
		}
		if (flag)
			return true;
		else
			return false;
	}
	bool isGoal(Cube* c)
	{
		if (match(c->front, 'W') && match(c->back, 'Y') && match(c->up, 'O') &&
			match(c->down, 'R') && match(c->right, 'B') && match(c->left, 'G'))
		{
			return true;
		}
		else
			return false;
	}

	bool compareSide(char s1[][3], char s2[][3])
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (s1[i][j] != s2[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}
	bool compareCube(Cube* c1, Cube* c2)
	{
		if (
			compareSide(c1->front, c2->front) &&
			compareSide(c1->back, c2->back) &&
			compareSide(c1->up, c2->up) &&
			compareSide(c1->down, c2->down) &&
			compareSide(c1->right, c2->right) &&
			compareSide(c1->left, c2->left)
			) {
			return true;
		}
		else
			return false;
	}
};

class node
{
	Cube* cube;
	node* parent;
	int rotation;
	vector<node*> moves; //rotations
public:
	node()
	{
		parent = nullptr;
		rotation = -1;
	}
	void setCube(Cube* c)
	{
		cube = c;
	}
	void setParent(node* n)
	{
		parent = n;
	}
	void printcube()
	{
		cube->printCube();
	}
	//getters
	vector<node*> getList()
	{
		return moves;
	}
	Cube* getCube()
	{
		return cube;
	}
	//retrun move
	string move(node* n)
	{
		string b = "Back Clockwise Rotation\n";
		string t = "Top Right Rotation\n";
		string d = "Down Right Rotation\n";
		string l = "Left Down Rotation\n";
		string r = "Right Down Rotation\n";
		string f = "Front Anti-clockwise Rotation\n";
		if (n->rotation == 0)
		{
			return b;
		}
		else if (n->rotation == 1)
		{
			return t;
		}
		else if (n->rotation == 2)
		{
			return f;
		}
		else if (n->rotation == 3)
		{
			return d;
		}
		else if (n->rotation == 4)
		{
			return l;
		}
		else if (n->rotation == 5)
		{
			return r;
		}
	}
	void setRotation(int r)
	{
		rotation = r;
	}
	//back tracking functions //back track from goal state
	void returnParent(node* n, stack<string>& s)
	{
		if (n->parent != nullptr)
		{
			string m = move(n);
			s.push(m);
			returnParent(n->parent, s);
		}
	}
	stack<string> returnMoves(node* goal)
	{
		stack <string>st;
		returnParent(goal, st);
		return st;
	}
	void returnCube(node* n, stack<Cube*>& s)
	{
		if (n->parent != nullptr)
		{
			s.push(n->getCube());
			returnCube(n->parent, s);
		}
	}
	stack <Cube*>returnStates(node* goal)
	{
		stack <Cube*>st;
		returnCube(goal, st);
		return st;
	}
};

class tree
{
	node* root;

public:
	tree()
	{
		root = new node();
	}
	tree(node* n)
	{
		root = n;
	}
	void pointCube(Cube* c)
	{
		root->setCube(c);
	}
	//BFS
	void levelOrder()
	{
		queue<node*> q;
		node* curr;
		q.push(root);
		vector<node*> visited;
		bool match = false;

		while (q.size() >= 1)
		{
			curr = q.front();
			q.pop();

			//check if already visited
			for (int i = 0; i < visited.size(); i++)
			{
				if (curr->getCube()->compareCube(visited[i]->getCube(), curr->getCube()))
				{
					curr = q.front();
					q.pop();
				}
			}
			//push if not visited
			visited.push_back(curr);

			Cube* cube = curr->getCube();
			match = cube->isGoal(cube);
			if (match)  //check if goal
			{
				stack<string>st = curr->returnMoves(curr);
				stack<Cube*> c = curr->returnStates(curr);
				printStack(st, c);
				break;
			}
			//pop and initialize
			vector<node*>moves = curr->getList();

			for (int i = 0; i < 6; i++)
			{
				node* newNode = new node;
				Cube* cube = new Cube(curr->getCube()->getFront(), curr->getCube()->getUp(), curr->getCube()->getDown()
					, curr->getCube()->getLeft(), curr->getCube()->getRight(), curr->getCube()->getBack());
				newNode->setCube(cube);
				newNode->setParent(curr);
				moves.push_back(newNode);
			}
			//call rotations and push children
			moves[0]->getCube()->backRotate(moves[0]->getCube());
			moves[0]->setRotation(0);
			q.push(moves[0]);

			moves[1]->getCube()->topRotate(moves[1]->getCube());
			moves[1]->setRotation(1);
			q.push(moves[1]);

			moves[2]->getCube()->frontRotate(moves[2]->getCube());
			moves[2]->setRotation(2);
			q.push(moves[2]);

			moves[3]->getCube()->downRotate(moves[3]->getCube());
			moves[3]->setRotation(3);
			q.push(moves[3]);

			moves[4]->getCube()->leftRotate(moves[4]->getCube());
			moves[4]->setRotation(4);
			q.push(moves[4]);

			moves[5]->getCube()->rightRotate(moves[5]->getCube());
			moves[5]->setRotation(5);
			q.push(moves[5]);
		}
	}
	//print moves and cubix
	void printStack(stack<string>s, stack<Cube*>c)
	{
		string str;
		cout << endl;
		cout << "Moves to reach the end goal:\n" << endl;
		int i = 1;
		while (!s.empty())
		{
			str = s.top();
			Cube* cube = c.top();
			cout << i << ") " << str << endl;
			cube->printCube();
			cout << endl;
			i++;
			s.pop();
			c.pop();
		}
	}
	void printcube()
	{
		root->printcube();
	}
};

int main()
{
	//initializing the cube
	char f[3][3] = {
			{ 'B', 'B', 'B' },
			{ 'W', 'W', 'R' },
			{ 'G', 'G', 'G' }
	};
	char r[3][3] = {
			{ 'O', 'Y', 'Y' },
			{ 'B', 'B', 'B' },
			{ 'W', 'W', 'R' }
	};
	char l[3][3] = {
			{ 'W', 'W', 'R' },
			{ 'G', 'G', 'G' },
			{ 'O', 'Y', 'Y' }
	};
	char b[3][3] = {
			{ 'G', 'G', 'G'},
			{ 'O', 'Y', 'Y'},
			{ 'B', 'B', 'B'}
	};
	char u[3][3] = {
			{'W', 'O', 'O'},
			{'W', 'O', 'O'},
			{'W', 'O', 'O'}
	};
	char d[3][3] = {
			{'R', 'R', 'Y'},
			{'R', 'R', 'Y'},
			{'R', 'R', 'Y'}
	};
	Cube* rubikscube = new Cube;
	rubikscube->initializeCube(f, b, l, r, u, d);
	tree obj;
	obj.pointCube(rubikscube);
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 15);
	cout << "\nINITIAL STATE OF THE CUBE\n\n";
	obj.printcube();
	obj.levelOrder();
}
