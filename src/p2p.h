#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "messageheader.h"
#include "libstring.h"
// #include "libstring.c" // is this needed?

struct p2p_peer {
  struct sockaddr_in   socket;
  struct p2p_peer * next_peer;
};

struct p2p_file {
  char filename[20];
  struct p2p_file * next_file;
};

struct p2p_peer * createPeer(char * argument);
int isPeerInList(struct p2p_peer * peers, struct p2p_peer * peer);
struct p2p_file * createFile(char * argument);
int isFileInList(struct p2p_file * files, struct p2p_file * file);
int getPeerPort(struct p2p_peer * peer);
char * getPeerIp(struct p2p_peer * peer);
