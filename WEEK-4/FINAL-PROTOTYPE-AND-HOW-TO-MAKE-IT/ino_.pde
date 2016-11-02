import processing.serial.*;
Serial myPort;  // Create object from Serial class
int val;        // Data received from the RSS feed

void setup(){
String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
}
//myPort = name for arduino? 

void draw(){
  XML xml;
 xml =loadXML("http://feeds.bbci.co.uk/news/politics/rss.xml"); 
 //RSS FEED CODING 'LANGUAGE' IS SPECIFIC TO BBC'S FEEDS (ie getchild/title/channel) 
 //other potential feeds that could be used with this code: 
 //http://feeds.bbci.co.uk/news/scotland/rss.xml (LOCAL SCOTLAND NEWS)
 //http://feeds.bbci.co.uk/news/world/rss.xml (WORLD NEWS)
 //http://feeds.bbci.co.uk/news/entertainment_and_arts/rss.xml (ARTS & ENTERTAINMENT)
 //http://feeds.bbci.co.uk/news/science_and_environment/rss.xml (SCIENCE)
 //http://feeds.bbci.co.uk/news/rss.xml (TOP STORIES)
 //http://feeds.bbci.co.uk/news/business/rss.xml (BUSINESS)
 //http://feeds.bbci.co.uk/news/health/rss.xml (HEALTH) 
 //http://feeds.bbci.co.uk/news/technology/rss.xml (TECHNOLOGY) 
 //http://feeds.bbci.co.uk/news/education/rss.xml (EDUCATION AND FAMILY, KIND OF A WEIRD ONE...)
 //CAN USE DIFFERENT FEEDS FOR DIFFERENT CONVERSATIONAL TOPICS? SERIES OF BOOKS?  
 
 XML channel = xml.getChild("channel");

XML[] items = channel.getChildren(); 

for(int i =19;i<40;i+=2){
   XML title = items[i].getChild("title");
//   XML newDesc = getContent(desc);
String text = title.getContent();
//Using a string instead of XML

int len = text.length();
int mod = 64%len;
println(mod);
 myPort.write(text);
 for(int j=0;j<mod;j++){
    myPort.write(" ");
 }
delay(5000);
//SPEED BETWEEN RSS STRINGS
}

}
