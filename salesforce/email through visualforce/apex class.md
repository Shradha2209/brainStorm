public class EmailController {

    public String toAddress { get; set; }
    public String subject { get; set; }
    public String body { get; set; }
    public String message { get; set; }

    public void sendEmail() {

        // Basic email validation
        if (String.isBlank(toAddress) ||
            !Pattern.matches('^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$', toAddress)) {
            message = 'Invalid Email ID';
            return;
        }

        Messaging.SingleEmailMessage mail =
            new Messaging.SingleEmailMessage();

        mail.setToAddresses(new String[] { toAddress });
        mail.setSubject(subject);
        mail.setPlainTextBody(body);

        Messaging.sendEmail(
            new Messaging.SingleEmailMessage[] { mail }
        );

        message = 'Email sent successfully!';
    }
}
