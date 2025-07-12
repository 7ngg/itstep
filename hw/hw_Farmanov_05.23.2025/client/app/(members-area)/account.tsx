import { View, Text, StyleSheet, Pressable } from "react-native";
import AsyncStorage from "@react-native-async-storage/async-storage";
import { useEffect, useState } from "react";
import { SafeAreaView } from "react-native-safe-area-context";
import Profile, { User } from "@/components/profile";
import { globalStyles } from "../global-styles";
import { useRouter } from "expo-router";

export default function Account() {
  const [user, setUser] = useState<User | null>(null);
  const router = useRouter();

  const handleSignOut = async () => {
    await AsyncStorage.removeItem("accessToken");
    router.push("/");
  };

  useEffect(() => {
    const fetchUser = async () => {
      const token = await AsyncStorage.getItem("accessToken");
      if (!token) return;

      try {
        const res = await fetch("http://192.168.100.3:8080/account", {
          method: "GET",
          headers: {
            Authorization: `Bearer ${token}`,
          },
        });

        if (!res.ok) {
          console.error("Failed to fetch user");
          return;
        }

        const data = await res.json();
        setUser(data);
      } catch (err) {
        console.error("Network error:", err);
      }
    };

    fetchUser();
  }, []);

  return (
    <SafeAreaView style={styles.container}>
      <View style={styles.card}>
        {user ? <Profile user={user!} /> : ""}
        <View
          style={{
            flexDirection: "row",
            gap: 8,
          }}
        >
          <Pressable style={styles.button} onPress={handleSignOut}>
            <Text>Sign out</Text>
          </Pressable>
        </View>
      </View>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  container: {
    backgroundColor: globalStyles.background,
    alignItems: "center",
    height: "100%",
    width: "100%",
  },
  card: {
    height: "50%",
    width: "90%",
    paddingVertical: 32,
    backgroundColor: globalStyles.backgroundLighter,
    borderWidth: 1,
    borderRadius: 10,
    alignItems: "center",
    justifyContent: "space-between",
    padding: 8,
  },
  button: {
    width: "90%",
    height: 40,
    alignItems: "center",
    justifyContent: "center",
    backgroundColor: globalStyles.accent,
    borderRadius: 10,
    borderWidth: 1,
  },
});
