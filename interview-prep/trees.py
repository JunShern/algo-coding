class Node(object):
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None
		self.parent = None

	def appendToTree(self, obj):
		if obj.data < self.data:
			if self.left == None:
				self.left = obj
				(self.left).parent = self
			else:
				leftChild = self.left
				leftChild.appendToTree(obj)
		else:
			if self.right == None:
				self.right = obj
				(self.right).parent = self
			else:
				rightChild = self.right
				rightChild.appendToTree(obj)

	def printTree(self):
		if (self.left != None): self.left.printTree()
		print(self.data)
		if (self.right != None): self.right.printTree()

lst = [4,3,2,15,3,3,2,6]

rootNode = Node(lst.pop(0))
while (len(lst) != 0):
	val = lst.pop(0)
	newNode = Node(val)
	rootNode.appendToTree(newNode)
