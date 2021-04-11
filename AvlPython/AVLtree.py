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

    @staticmethod
    def getHeight(node):
        return node.height if node else 0

    def _bfactor(self):
        return self.getHeight(self.right) - self.getHeight(self.left)

    def _fixHeight(self):
        self.height = max(self.getHeight(self.left), self.getHeight(self.right)) + 1

    def _rRight(self):
        tree = AVLTree(self.val)
        tree.update(self)

        newTree = tree.left
        tree.left = newTree.right
        newTree.right = tree
        tree._fixHeight()
        newTree._fixHeight()

        self.update(newTree)

    def _rLeft(self):
        tree = AVLTree(self.val)
        tree.update(self)

        newTree = tree.right
        tree.right = newTree.left
        newTree.left = tree
        tree._fixHeight()
        newTree._fixHeight()

        self.update(newTree)

    def _balance(self):
        self._fixHeight()
        if (self._bfactor() == 2):
            if (self.right._bfactor() < 0):
                self.right._rRight()
            self._rLeft()
        elif (self._bfactor() == -2):
            if (self.left._bfactor() > 0):
                self.left._rLeft()
            self._rRight()

    def findmin(self):
        return self.left.findmin() if self.left else self

    def removemin(self):
        if self.left == None:
            return self.right
        self.left = self.left.removemin()
        self._balance()
        return self

    def insert(self, val):
        if val < self.val:
            if self.left:
                self.left.insert(val)
            else:
                self.left = AVLTree(val)
        elif val > self.val:
            if self.right:
                self.right.insert(val)
            else:
                self.right = AVLTree(val)
        self._balance()

    def find(self, val):
        if val < self.val:
            return self.left.find(val) if self.left else False
        elif val > self.val:
            return self.right.find(val) if self.right else False
        else:
            return True

    def remove(self, val):
        if not self.find(val):
            return False
        if self.height == 1:
            return True
        else:
            return self._remove(val)

    def _remove(self, val):
        if val < self.val:
            if self.left.left == None and self.left.right == None:
                self.left = None
                return True
            else:
                self.left._remove(val)
        elif val > self.val:
            if self.right.left == None and self.right.right == None:
                self.right = None
                return True
            else:
                self.right._remove(val)
        else:
            tree = AVLTree(self.val)
            tree.update(self)
            l = tree.left
            r = tree.right
            if (r == None):
                self.update(l)
            else:
                m = r.findmin()
                m.right = r.removemin()
                m.left = l
                self.update(m)
        self._balance()
        return True

    def __str__(self):
        leftIn = str(self.left) if self.left else ""
        rightIn = str(self.right) if self.right else ""
        if len(leftIn) > 0:
            leftIn = "(" + leftIn + ")"
        if len(rightIn) > 0:
            rightIn = "(" + rightIn + ")"
        return leftIn + str(self.val) + rightIn

    def __del__(self):
        del self


def main():
    tree = AVLTree(1)
    tree.insert(2)
    tree.insert(5)
    tree.insert(6)
    tree.insert(3)
    print(tree)
    tree.remove(5)
    print(tree)
    tree.remove(2)
    print(tree)
    tree.remove(3)
    print(tree)
    tree.remove(6)
    print(tree)
    tree.remove(1)
    print(tree)
    for i in [-30714, 39586, 33217, 34756, 22403, 24117, 34261, -49443, -23765, 23920, 19227, -29927, -35293, 30612]:
        tree.insert(i)
    print(tree)
    print(tree.find(2))
    print(tree.remove(2))
    print(tree)


if __name__ == '__main__':
    main()
