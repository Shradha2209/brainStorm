public class ConsoleEmailSender {

    public static void sendEmail(
        String toAddress,
        String subject,
        String body
    ) {
        // Basic email validation
        if (String.isBlank(toAddress) ||
            !Pattern.matches(
                '^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$',
                toAddress
            )) {
            System.debug('Invalid Email ID');
            return;
        }

        // Create email message
        Messaging.SingleEmailMessage mail =
            new Messaging.SingleEmailMessage();

        mail.setToAddresses(new String[] { toAddress });
        mail.setSubject(subject);
        mail.setPlainTextBody(body);

        // Send email
        Messaging.sendEmail(
            new Messaging.SingleEmailMessage[] { mail }
        );

        System.debug('Email sent successfully!');
    }
}
