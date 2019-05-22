#include "gen-cpp/Hello.h"
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>

//#include <boost/exception/exception.hpp>

#include <iostream>
#include <string>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;

//using boost::shared_ptr;

int main(int argc, char *argv[])
{
	std::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
	std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));


	/*::apache::thrift::stdcxx::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
	::apache::thrift::stdcxx::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	::apache::thrift::stdcxx::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));*/

	// ֻ��Ҫʵ���� HelloClient��Ȼ��Ϳ���Զ�̹��̵�����
	Demo::HelloClient client(protocol);

	try
	{
		transport->open();

		// ����RPC Server�ķ���
		std::cout << "�������ظ������֣�" << client.helloInt(102345) << std::endl;
		std::string strHello = "hello from Client";
		std::string strReturn;
		client.helloString(strReturn, strHello);
		std::cout << "�������ظ����ַ�����" << strReturn << std::endl;

		transport->close();
	}
	catch (const TException& e)
	{
		std::cout << "Error:" << e.what() << std::endl;
	}
	

	system("pause");
	getchar();

	return 0;
}
