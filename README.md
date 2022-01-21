## CPS2004 - OOP Assignment

### Task 1 - DAG (in C++)

Build a templatized directed acyclic graph data structure. The graph has to
support objects of arbitrary types and encapsulate them inside nodes. It is
up to you to design the API, however it has to support the following features:
2
 The graph data structure needs to own the idividual objects.
 The constructor needs to take a list of edges (with obvious checks such
as cycles). The ownership of the objects needs to be moved from this list
to the graph.
 A method to remove individual nodes.
 A method to return the list of edges, without destroying the in-memory
graph structure.
At face value this looks like a very easy question, but marks will be awarded
for how elegant, efficient, concise, and correct your code is. You can start
working on this before we cover templates, and add templates later.


### Task 2 - Crypto Exchange (in Java)

Design a simple crypto exchange platform, emphasizing the concepts in
boldface. Implement some simple functionality where appropriate and write
unit tests that exercise this logic.
A commercial exchange would take months to develop, so in this exercise I will be looking at your ability to apply the design principles
discussed in class to an artificial problem. You do not need to implement
a GUI or CLI. You do not need persistance, nor networking support. The
requirements below are not fully specified, but hopefully not conflicting. It
will be up to you to interpret these in a way that respects the intention of the
client (the examiner).
An exchange platform is a facility where traders can buy and sell different
kinds of CRYPTO for FIAT currencies. Users of the exchange have to
REGISTER and be APPROVED by the ADMINISTRATORS in order to
use the system. Therefore there are two types of users: TRADERS and
ADMINISTRATORS. To be able to trade a CRYPTO on this stock exchange.
There are various kinds of CRYPTO, each having its own information: total
supply, decimals, symbol, etc.
The exchange platform maintains an ORDER BOOK.
Orders can be BUY ORDERS, SELL ORDERS. Each order can also can
be a MARKET order or LIMIT order. Orders are placed by a trader, and
include a QUANTITY. In addition they have a BID or ASK price in case
they’re buying or selling respectively. Market orders do not have a bid or ask
price. When orders are sent to the platform, the platform places these on
the order book, which is visible to every trader. The system will try to FILL
orders by matching buy and sell order prices together using a MATCHING
ENGINE. This can be done by maintaining a sorted (by price) data structure
of orders and matching these in a first-come first-served manner. Some orders
will be FILLED, some won’t and some will be partially FILLED. Orders that
3
Figure 1: An order book in a real exchange (sorted by price).
Figure 2: Examples of orders in an exchange.
are partially FILLED may start have their VOLUME EXECUTED quantity
increase as more matching orders are executed, until they become fully filled.
Unfilled orders can also be CANCELLED.
Please design your system in such a way as to facilitate future changes,
because additional requirements may come up at short notice. Please
justify how your system can be easily changed to implement the following
requirement:
 Audit trails: The FATF has just imposed new regulations on the government, who has in turn threatened to close down the exchange. In
order to avoid closure, your boss asks that every action by a user needs
to produce a log (that cannot be tampered with) so that any fraudulent
activity can be investigated by competent authorities and scenarios
recreated.
 On the other hand, you realize that modifying all the classes and
methods will take too much time to meet the deadline. Describe a
technical solution of your preference

### Task 3 - Big Integers (in C++)

C++ supports a number of integer types, but not all. Many cryptographic
algorithms need to use 256-bit or 512-bit numbers, or even larger.
Write a templated integer library that supports integers, from 1-bit to
2048-bits.

This library must only support unsigned integers with 2^n bits. A compilation error should be emitted if the user tries to use an arbitrary length integer.
Solutions that make use of bitsets or strings will not be accepted.
Detailed instructions:
1. Design the library, implement and overload all binary integer operators
(except *, /, %), a templated conversion function, together with move
and copy constructors from integer types. Getting the design right, so as
not to re-implement a lot of functionality will be one of your challenges.
A good implementation can be done with very little code, and should
be enough to get a decent mark. (18 marks)
2. Implement operators *, /, % (6 marks).
3. Make your implementation efficent: space, time, and code. In order
to optimize space and time, the templated library should be able to
automatically switch to built in integers if it can, without additional
overhead. For those feeling really adventurous, go ahead and use bit
manipulation techniques or modern CPU features (e.g., AVX...) to reduce
overhead, but this is not a requirement (you may find godbolt.org to
be useful if you go down this path). To get efficiency in code size, it
is important to understand C++ semantics and OO concepts so as to
better exploit templates and other modularity techniques. Document
any design or implementation features related to efficiency. (9 marks)
