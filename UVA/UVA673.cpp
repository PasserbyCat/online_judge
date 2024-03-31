#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
	char input[ 1000 ];
	cin.getline( input, 1000 );
	long long number = 0;
	for( int i = 0; input[ i ] != '\0'; i++ ) {
		number *= 10;
		number += input[ i ] - '0';
	}
	for( int i = 0; i < number; i++ ) {
		cin.getline( input, 1000 );
		stack<char> all;
		for( int j = 0; input[ j ] != '\0'; j++ ) {
			if( input[ j ] == '(' || input[ j ] == '[' )
				all.push( input[ j ] );
			else if( all.size() != 0 ) {
				if( input[ j ] == ')' ) {
					if ( all.top() == '(' )
						all.pop();
					else all.push( input[ j ] );
				}
				else if( input[ j ] == ']' ) {
					if( all.top() == '[' )
						all.pop();
					else all.push( input[ j ] );
				}
				else all.push( input[ j ] );
			}
			else if( input[ j ] == ')' || input[ j ] == ']' ) {
				all.push( input[ j ] );
			}
		}
		if( all.size() == 0 )
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}