#include<iostream>
#include "BitStreams.h"
#include "BinaryTree.h"
#include "VariousExceptions.h"
using namespace std;

void treeBuilder(InBitStream& file , BinaryTree<int>& tree, BinaryTree<int>::Iterator& location){
  int bit = file.read();
  if(bit==0){
    //step to the left indicated by 0, step to the right indicated by 1
    while(location.hasLeftChild() && location.hasRightChild()){
      location = location.up();
      }
    if(!location.hasLeftChild()){
      tree.insertAsLeftChild(location, 0);
      location = location.left();
      }
    else{
      tree.insertAsRightChild(location, 0);
      location = location.right();
      } 
    treeBuilder(file, tree, location);
    }
  else{
    if(!location.hasLeftChild()){
      tree.insertAsLeftChild(location, file.read(9));
      treeBuilder(file, tree, location);
      }
    else{
      tree.insertAsRightChild(location, file.read(9));
      }
    }
  }


void decodeMessage(BinaryTree<int>& tree, InBitStream& file, OutBitStream& outfile){
   BinaryTree<int>::Iterator pos = tree.root();
   if(!pos.isLeaf()){
     int bit = file.read();
     if( bit == 0){
       pos= pos.left();
       }
     else{
       pos = pos.right();
       }
     }
   else{
     outfile.write(*pos);
     }
   if(*pos != 257){
     decodeMessage(tree, file, outfile);
     }
   }
      
int main(){
  string filename;
  string decodedfile;
  cout << "Type the name of the compressed file to decode" <<endl;
  cin >> filename;
  cout << "Type what the name of the decompressed file is" <<endl;
  cin >> decodedfile; 
  
  InBitStream::filename.open();

  BinaryTree<int> huffTree;
  huffTree.createRoot(filename.read());
  BinaryTree<int>::Iterator pos = huffTree.root();
  treeBuilder(filename, huffTree, pos);
  decodeMessage(huffTree, filename, decodedfile);
}
