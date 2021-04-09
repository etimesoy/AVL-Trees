class AVLTree:
    def __init__(self, val):
        self.val = val
        self.height = 1
        self.left = self.right = None

    def update(self, other):
        self.val = other.val
        self.height = other.height
        self.left = other.left
        self.right = other.right

    def getHeight(self):
        return self.height if self else 0

    def bfactor(self):
        return self.right.getHeight() - self.left.getHeight()

    def fixHeight(self):
        self.height = max(self.left.getHeight(), self.right.getHeight())

    def rRight(self):
        tree = AVLTree(self.val)
        val.update(self)

        newTree = tree.left
        tree.left = newTree.right
        newTree.right = tree
        tree.fixHeight()
        newTree.fixHeight()

        self.update(newTree)

    def rLeft(self):
        tree = AVLTree(self.val)
        val.update(self)

        newTree = tree.right
        tree.right = newTree.left
        newTree.left = tree
        tree.fixHeight()
        newTree.fixHeight()

        self.update(newTree)

    def balance(self):
        self.fixHeight()
        if (self.bfactor() == 2):
            if (self.right.bfactor()):
                self.right.rRight()
            self.rLeft()
        elif (self.bfactor() == -2):
            if (self.left.bfactor() > 0):
                self.left.rLeft()
            self.rRight()

    def findmin(self):
        return self.left.findmin() if self.left else self

    def removemin(self):
        if (self.left == None):
            return self.right
        self.left = self.left.removemin()
        self.balance()
        return self

    def insert(self, val):
        if (val < self.val):
            if (self.left):
                self.left.insert(val)
            else:
                self.left = AVLTree(val)
        elif (val > self.val):
            if (self.right):
                self.right.insert(val)
            else:
                self.right = AVLTree(val)
        if (self.left and self.right):
            self.balance()

    def find(self, val):
        if (val < self.val):
            return self.left.find(val) if self.left else False
        elif (val > self.val):
            return self.right.find(val) if self.right else False
        else:
            return True

    def remove(self, val):
        if (not self.find(val)):
            return False
        if (val < self.val):
            self.left.remove(val)
        elif (val > self.val):
            self.right.remove(val)
        else:
            tree = AVLTree(self.val)
            tree.update(self)
            l = tree.left
            r = tree.right
            if (not r):
                self.update(l)
            else:
                m = r.findmin()
                m.right = r.removemin()
                m.left = l
                self.update(m)

        self.balance()
        return True

    def __str__(self):
        leftIn = str(self.left) if self.left else ""
        rightIn = str(self.right) if self.right else ""
        if (len(leftIn)>0):
            leftIn = "(" + leftIn + ")"
        if (len(rightIn)>0):
            rightIn = "(" + rightIn + ")"
        return leftIn + str(self.val) + rightIn

def main():
    tree = AVLTree(3)
    tree.insert(2)
    tree.insert(5)
    tree.insert(6)
    tree.insert(1)
    print(tree)
    print(tree.find(2))
    print(tree)


if __name__ == '__main__':
    main()
