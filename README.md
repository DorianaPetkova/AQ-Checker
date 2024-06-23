
<body>
    <h1>Air Quality Checker</h1>
    <div class="section">
        <h2>Overview</h2>
        <p>Air Quality Checker uses ThingSpeak to monitor the air quality and provide a statistical report. We decided to create this monitoring system because we wanted to ensure people with diminished capabilities are safe and sound.</p>
    </div>
    <div class="section">
        <h2>Required Hardware</h2>
        <ul>
            <li>MH MQ Sensor</li>
            <li>Wemos D1 R32</li>
            <li>Cables</li>
            <li>LED I2C</li>
        </ul>
    </div>
    <div class="section">
        <h2>Required Software</h2>
        <ul>
            <li>ThingSpeak account</li>
            <li>Arduino IDE</li>
            <li>Board: ESP32 Dev Module</li>
            <li>Library: LiquidCrystal I2C by Frank</li>
        </ul>
    </div>
    <div class="section">
        <h2>Connections</h2>
        <ul>
            <li><strong>LED I2C</strong>
                <ul>
                    <li>GND to GND of Wemos</li>
                    <li>VCC to 5V of Wemos</li>
                    <li>SDA to SDA of Wemos</li>
                    <li>SCL to SCL of Wemos</li>
                </ul>
            </li>
            <li><strong>MH MQ Sensor</strong>
                <ul>
                    <li>AO to IO2 of Wemos</li>
                    <li>DO to GND of Wemos</li>
                    <li>VCC to 5V of Wemos</li>
                </ul>
            </li>
        </ul>
        <img src="Group 2.png" alt="what to do">
    </div>
    <div class="section">
        <h2>Circuit Diagram</h2>
        <p>(Insert Circuit Diagram Image Here)</p>
    </div>
    <div class="section">
        <h2>How to set up ThingSpeak</h2>
        <ul>
            <li>Create an account and sign in</li>
            <li>Create a new channel - while creating make one field named 'Air Quality Checker'</li>
            <li>Go to the 'API keys' tab under your created channel and put your API key into the code</li>
        </ul>
    </div>
    <div class="section">
        <h2>Code Explanation</h2>
        <ol>
            <li><strong>Libraries and Constants Initialization</strong>
                <p>The code begins by including necessary libraries for I2C communication (<code>Wire.h</code>), WiFi functionality (<code>WiFi.h</code>), and for controlling the LCD (<code>LiquidCrystal_I2C.h</code>).</p>
                <p>An instance of the <code>LiquidCrystal_I2C</code> class is created with the I2C address <code>0x27</code> and a 16x2 character display size.</p>
                <p>The analog pin for the gas sensor is defined as <code>GAS_SENSOR_PIN</code> and set to pin <code>34</code>.</p>
            </li>
            <li><strong>Variable Declarations</strong>
                <p>A float variable <code>t</code> is initialized to store the gas sensor readings.</p>
                <p>A string variable <code>apiKey</code> is initialized with the API key for ThingSpeak.</p>
            </li>
            <li><strong>Setup Function</strong>
                <p>The <code>setup()</code> function initializes the LCD and sets the backlight on.</p>
                <p>The LCD displays "Welcome to" and "AQ Checker" on the first and second lines, respectively.</p>
                <p>The gas sensor pin mode is set to <code>INPUT</code>.</p>
                <p>Serial communication is started at a baud rate of 115200.</p>
                <p>The code attempts to connect to the WiFi network displaying "Connecting to WiFi" on both the serial monitor and the LCD.</p>
                <p>Once connected to WiFi, it updates the serial monitor and LCD to show "Connected to WiFi" and "Processing :".</p>
            </li>
            <li><strong>Loop Function</strong>
                <p>The <code>loop()</code> function continuously reads the gas sensor value and stores it in <code>t</code>.</p>
                <p>The air quality value <code>t</code> is printed to the serial monitor and displayed on the LCD.</p>
                <p>The function <code>esp_8266()</code> is called to send the data to ThingSpeak.</p>
                <p>A delay of 17 seconds is included to comply with ThingSpeak's 16-second update requirement.</p>
            </li>
            <li><strong>Sending Data to ThingSpeak</strong>
                <p>The <code>esp_8266()</code> function establishes a connection to ThingSpeak's server.</p>
                <p>If the connection fails, it prints an error message to the serial monitor and updates the LCD accordingly.</p>
                <p>If the connection is successful, it constructs the URL for the HTTP GET request using the API key and the sensor reading.</p>
                <p>The URL is printed to the serial monitor, and the GET request is sent to ThingSpeak.</p>
                <p>After a short delay, it confirms on the serial monitor and the LCD that the data has been sent to ThingSpeak.</p>
            </li>
        </ol>
    </div>
    <div class="section">
        <h2>Testing</h2>
        <ul>
            <li>Place the sensor in a room with clean air. If you see low numbers that means it works.</li>
            <li>Place the sensor near a car or stove. If you see high numbers that means it works.</li>
            <li>Check ThingSpeak and look at your channel stats on Field 1 Chart.</li>
        </ul>
    </div>
    <div class="section">
        <h2>Troubleshooting</h2>
        <ul>
            <li>Check all connections and ensure they are properly secured.</li>
            <li>Make sure you've added your WiFi name/password, as well as your API key into the code.</li>
            <li>Ensure that the LED's potentiometer is working properly.</li>
             <img src="group 1.png" alt="what to do">
        </ul>
    </div>
    <div class="section contact-info">
        <p>This project was created by the one and only : "Ponylypsis"</p>
        <p>Irina Semenyakina - <a href="mailto:kittifeya@gmail.com">kittifeya@gmail.com</a></p>
        <p>Doriana Petkova – <a href="mailto:doriana.petkova@gmail.com">doriana.petkova@gmail.com</a></p>
         <img src="ponies.png" alt="The team">
    </div>
</body>
</html>
