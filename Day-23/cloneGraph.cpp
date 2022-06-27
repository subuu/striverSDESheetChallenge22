/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
graphNode *helper(graphNode *node,unordered_map <int, graphNode*> &visitedmp) 
   {
       graphNode *newnode = new graphNode(node->data);
       visitedmp[newnode->data] = newnode; 
  
       for(graphNode* temp : node->neighbours)
       {
           if(visitedmp.find(temp->data) == visitedmp.end())
               newnode->neighbours.push_back(helper(temp,visitedmp));
           else
               newnode->neighbours.push_back(visitedmp[temp->data]);  
       }
       return newnode;
   }
    
    
graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
     if(!node) return NULL;
     unordered_map <int, graphNode*> visitedmp;
     return helper(node, visitedmp);  
}