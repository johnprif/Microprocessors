//6_2_a
module MCPU_RAMController_tb();
  parameter WORD_SIZE=8;
  parameter ADDR_WIDTH=8;
  parameter RAM_SIZE=1<<ADDR_WIDTH;

  reg we, re;

  reg [WORD_SIZE-1:0] datawr;

  reg [ADDR_WIDTH-1:0] addr;
  reg [ADDR_WIDTH-1:0] instraddr;

  wire [WORD_SIZE-1:0] datard;
  wire [WORD_SIZE-1:0] instrrd;

  reg [WORD_SIZE-1:0] golden_reference[RAM_SIZE-1:0]; //Memory box
  reg iscorrect; //To check the result
  integer i; //for our forloop
  //memory instance
  MCPU_RAMController #(.WORD_SIZE(WORD_SIZE), .ADDR_WIDTH(ADDR_WIDTH), .RAM_SIZE(RAM_SIZE)) raminst (.we(we), .datawr(datawr), .re(re), .addr(addr), .datard(datard), .instraddr(instraddr), .instrrd(instrrd));
  
initial
begin
  //write random data to memory 
  for(i=0; i<RAM_SIZE; i=i+1)
  begin
    #2
    golden_reference[i]=$random;
    we=1;
    re=0;
    addr=i;
    datawr=golden_reference[i];    
  end
  //read the written data from memory
  for(i=0; i<RAM_SIZE; i=i+1)
  begin
    we=0;
    re=1;
 	  addr=i;
    instraddr=i;
    #2  
    if((datard==golden_reference[i]) && (instrrd==golden_reference[i]))
    begin
      iscorrect=1;
    end  
    if((datard!=golden_reference[i]) || (instrrd!=golden_reference[i]))
    begin
      iscorrect=0;
    end
  end
end
  
  
endmodule