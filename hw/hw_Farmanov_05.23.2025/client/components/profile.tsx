import { View, Image, StyleSheet, Text } from "react-native";

export interface User {
  id: string;
  username: string;
  imgUrl: string;
  memberForDays: number;
}

export interface ProfileProps {
  user: User;
}

export default function Profile({ user }: ProfileProps) {
  const imgSource =
    user.imgUrl.length != 0
      ? { uri: user.imgUrl }
      : require("@/assets/images/profile.png");
  return (
    <View style={styles.container}>
      <Image source={imgSource} style={styles.image} />
      <View>
        <Text style={styles.boldText}>{user.username}</Text>
        <Text>Member for {user.memberForDays} day(s)</Text>
        <Text>
          <Text style={{ fontWeight: 700 }}>ID: </Text>
          {user.id}
        </Text>
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    alignItems: "center",
    gap: 8
  },
  image: {
    width: 150,
    height: 150,
    borderRadius: 75,
    borderWidth: 1,
  },
  boldText: {
    fontSize: 24,
  },
});
