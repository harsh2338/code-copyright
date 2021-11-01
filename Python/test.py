from unittest import TestCase
import io
from unittest.main import main

import pytest
from antlr4 import *
# from antlr4.error.ErrorListener import *
# import antlr4.error.ErrorListener as ErrorListener
from Python3Lexer import Python3Lexer
from Python3Parser import Python3Parser
from Python3Listener import Python3Listener


class Python3ErrorListener():
    def __init__(self, output):
        self.output = output
        self._symbol = ''

    def syntaxError(self, recognizer, offendingSymbol, line, column, msg, e):
        self.output.write(msg)
        self._symbol = offendingSymbol.text
        stack = recognizer.getRuleInvocationStack()
        stack.reverse()
        print("rule stack: {}".format(str(stack)))
        print("line {} : {} at {} : {}".format(str(line),
                                               str(column),
                                               str(offendingSymbol).replace(" ", u'\u23B5'),
                                               msg.replace(" ", u'\u23B5')))

    @property
    def symbol(self):
        return self._symbol


class Python3ParserTests(TestCase):

    def __init__(self):
        self.test_python3_test_grammar()
    
    def setup(self, path):
        input = FileStream(path)
        lexer = Python3Lexer(input)
        stream = CommonTokenStream(lexer)

        # print out the token parsing
        stream.fill()
        print("TOKENS")
        for token in stream.tokens:
            if token.text != '<EOF>':
                type_name = Python3Parser.symbolicNames[token.type]
                tabs = 5 - len(type_name) // 4
                sep = "\t" * tabs
                print("    %s%s%s" % (type_name, sep,
                                      token.text.replace(" ", u'\u23B5').replace("\n", u'\u2936')))
        parser = Python3Parser(stream)

        self.output = io.StringIO()
        self.error = io.StringIO()

        parser.removeErrorListeners()
        self.errorListener = Python3ErrorListener(self.error)
        parser.addErrorListener(self.errorListener)
        return parser

    def test_python3_test_grammar(self):
        parser = self.setup("hello_world.py")
        tree = parser.file_input()
        print(tree)
        listener = Python3Listener()
        walker = ParseTreeWalker()
        walker.walk(listener, tree)
        self.assertEqual(len(self.errorListener.symbol), 0)


Python3ParserTests()