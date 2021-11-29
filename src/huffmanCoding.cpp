//huffman encoding and decoding
//inspriation found from www.techiedelight.com/huffman-coding/ 


#include <iostream> // standard c++ include
#include <unordered_map> // occurrences of each character
#include <queue> // for priority key
#include <string> //for the "cout" commands

using namespace std; //standard c++ command


////////////////////////////////////////////////////////////////////
//                        Structure Declarations:
struct unitNode // structure of each node in the tree.
{   char currentCharacter; // will have the current character / value of the node
	int numberOfEachChar; // frequency
	unitNode *left, *right; //left and right nodes for this node if applicable
};
struct compareNodes // does left or right node have higher frequency 
{
	bool operator()(const unitNode* left, const unitNode* right) const{ //CONST MAY NOT BE NEEDED !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		// higher in the prioity key, the less that value appeared in the string / unordered maps
		if (left->numberOfEachChar > right->numberOfEachChar) {
			return true; // left has more than right, return true to be used later
		}
		else {
			return false; //right has more than left, return false to be used later
		}
	}
};
////////////////////////////////////////////////////////////////////
unordered_map<char, int> sortTree(string input) { // We were going to do loops and conditional statements but it wasn't working, looked into hashing and it seemed an unordered map is the best solution
	unordered_map<char, int> numberOfEachChar;
	for (char currentCharacter : input) { // go through each input character and....
		numberOfEachChar[currentCharacter]++; //hash table like, search for current element, increment this spot by 1 
	}
	return numberOfEachChar; // return the map
}

unitNode* newNode(char currentCharacter, int numberOfEachChar, unitNode* left, unitNode* right) { //function to create new node, a lot of this function uses code similar to the "this" functions
	unitNode * thisIsTheNewNode = new unitNode(); // actually create new node
	thisIsTheNewNode->numberOfEachChar = numberOfEachChar; // assign the number of each character / frequency (which was passed) to the frequency pointer node
	thisIsTheNewNode->currentCharacter = currentCharacter; // assign the current character (which was passed) to the current character pointer node
	thisIsTheNewNode->right = right; // assign the right node (which was passed) to the right pointer node
	thisIsTheNewNode->left = left; // assign the left node (which was passed) to the left pointer node
	return thisIsTheNewNode;
}

void createTree(string input); // function declaration


int main() {
	string input = "I am currently testing?"; // testing purposes as we don't have inputs yet
		createTree(input); // call the create tree function which converts the string 

	
	return 0; //return for main. 
}

void encodeHuffman(unitNode* rootOfHuffmanTree, string passedString, unordered_map<char, string> &huffmanEncoding) { // encode function
	if (rootOfHuffmanTree == nullptr) { // if root is null, nothing left to encode
		return; // leave
	}

	if (rootOfHuffmanTree->left == nullptr && rootOfHuffmanTree->right == nullptr) { // if the leaf nodes are null, this is the root
		huffmanEncoding[rootOfHuffmanTree->currentCharacter] = (passedString != "") ? passedString : "1"; // encode again (recursion) but set as root. If string isn't empty, send the str, otherwise send 1
	}

	encodeHuffman(rootOfHuffmanTree->left, passedString + "0", huffmanEncoding); // recursively encode again but with the left leaf and use the 0 to signify left leaf
	encodeHuffman(rootOfHuffmanTree->right, passedString + "1", huffmanEncoding); //recursively encode again but with the right leaf and use the 1 to signify right leaf
}

void decodeHuffman(unitNode* rootOfHuffmanTree, int &currentIndex, string passedString) { //decode function
	if (rootOfHuffmanTree == nullptr) { // if nothing at root
		return; // function is done, leave it
	}

	if (rootOfHuffmanTree->left == nullptr && rootOfHuffmanTree->right == nullptr) { // if the left and right leaves are nothing, this is the root. Set it to the root, and leave
		cout << rootOfHuffmanTree->currentCharacter; // print the root (this is the current decoding info)
		return; // leave
	}

	currentIndex++; // increment the index

	if (passedString[currentIndex] == '0') { // if the passed string is 0 (see encode function), then we know its the left leaf
		decodeHuffman(rootOfHuffmanTree->left, currentIndex, passedString); //recursively decode with left leaf
	}
	else { //otherwise it has to be the right leaf 
		decodeHuffman(rootOfHuffmanTree->right, currentIndex, passedString); //recursively decode with right leaf
	}

}


void createTree(string input) {
	if (input == "") {
		// string is empty, nothing to encode
		cout << "got empty string"; // for error handling, should not see this
	}
	
	unordered_map<char,int> numberOfEachChar = sortTree(input); // parse the input and count frequency of each unsigned char
	// at this point we have arrays with the occurency of each value as it's value

	
	// considered using a heap however a priority queue essentially accompishes the same thing and is easier (in our opinion) to implement
	priority_queue<unitNode*, vector<unitNode*>, compareNodes> priorityQueue;

	for (auto leafNode : numberOfEachChar) { //shortcut for loop command, quite useful
		priorityQueue.push(newNode(leafNode.first, leafNode.second, nullptr, nullptr)); //create a new node and add it to the queue for all the input data
	}

	while (1) { // loop forever - see the else case below for how to get out of the loop
		if (priorityQueue.size() != 1) { // if the size isn't one there's more to add
			unitNode* left = priorityQueue.top(); priorityQueue.pop(); //set the left for current node, take it off the queue
			unitNode* right = priorityQueue.top(); priorityQueue.pop(); //set the right for current node, take it off the queue


			int leftAndRightNumberOfEachChar = left->numberOfEachChar + right->numberOfEachChar; // how many occurences on the left and right side?
			priorityQueue.push(newNode('\0', leftAndRightNumberOfEachChar, left, right)); // now we push this new node with left and right information back on the queue. Root has pointers to its leaves
		}
		else {
			break; // if the size of the queue is 1, no left and right to pop, just the root left, leave the loop
		}

		
	}

	unitNode* rootOfHuffmanTree = priorityQueue.top(); // current root is going to the top of the priority queue. This function is with the include <unordered_map> 


	unordered_map<char, string> huffmanEncoding; // create a new map of character and strings this time, and then encode in the next line...
	encodeHuffman(rootOfHuffmanTree, "", huffmanEncoding); // call encode function

	cout << "Huffman Codes as encoded:\n";
	for (auto codes : huffmanEncoding) { //another auto loop, go through the map
		cout << codes.first << " " << codes.second << "\n"; //print the character and the associated huffman code
	}

	cout << "Input was:\n" << input; // print input string to compare to decode function

	string encodedOutput; //this is the variable for the encoded output
	for (char currentCharacter : input) { // go through each character in the loop
		encodedOutput += huffmanEncoding[currentCharacter]; // add the huffman code for the current character to the overall encoded output
	}

	cout << "\nThe encoded string is:\n" << encodedOutput << endl; // print encoded string as calculated above
	cout << "\nThe decoded string is:\n"; // now decode the above string 

	int loopCondition = -1; // new var for while loop, and to pass to decode function
	while (loopCondition < (int)encodedOutput.size() -1 ) { // loop as long as -1 is less than the size of the encoded output, since there is more to decode
		decodeHuffman(rootOfHuffmanTree, loopCondition, encodedOutput); // decode current root.
	}

}



